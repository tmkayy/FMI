package bg.sofia.uni.fmi.mjt.order.analyzer;

import bg.sofia.uni.fmi.mjt.order.domain.Category;
import bg.sofia.uni.fmi.mjt.order.domain.Order;
import bg.sofia.uni.fmi.mjt.order.domain.PaymentMethod;
import bg.sofia.uni.fmi.mjt.order.domain.Status;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.EnumMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.Set;
import java.util.stream.Collectors;

public class OrderAnalyzerImpl implements OrderAnalyzer {
    private final List<Order> orders;

    private static final int SUSPICIOUS_ORDER_THRESHOLD = 3;
    private static final double MIN_SUSPICIOUS_TOTAL_SALES = 100.0;

    public OrderAnalyzerImpl(List<Order> orders) {
        if (orders == null) {
            throw new IllegalArgumentException("Orders list cannot be null");
        }
        this.orders = new ArrayList<>(orders);
    }

    @Override
    public List<Order> allOrders() {
        return List.copyOf(orders);
    }

    @Override
    public List<Order> ordersByCustomer(String customer) {
        if (customer == null || customer.isBlank()) {
            throw new IllegalArgumentException("Customer name cannot be null or blank");
        }

        return orders.stream()
            .filter(order -> customer.equals(order.customerName()))
            .toList();
    }

    @Override
    public Map.Entry<LocalDate, Long> dateWithMostOrders() {
        if (orders.isEmpty()) {
            return null;
        }

        return orders.stream()
            .collect(Collectors.groupingBy(Order::date, Collectors.counting()))
            .entrySet().stream()
            .max(Comparator
                .comparingLong(Map.Entry<LocalDate, Long>::getValue)
                .thenComparing(Map.Entry::getKey, Comparator.reverseOrder()))
            .orElse(null);
    }

    @Override
    public List<String> topNMostOrderedProducts(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("n cannot be negative");
        }
        if (n == 0) {
            return List.of();
        }

        Map<String, Long> productFrequency = orders.stream()
            .collect(Collectors.groupingBy(Order::product, Collectors.counting()));

        Comparator<Map.Entry<String, Long>> comparator = (e1, e2) -> {
            int countCompare = e2.getValue().compareTo(e1.getValue());
            if (countCompare != 0) {
                return countCompare;
            }
            return e1.getKey().compareToIgnoreCase(e2.getKey());
        };

        return productFrequency.entrySet().stream()
            .sorted(comparator)
            .limit(n)
            .map(Map.Entry::getKey)
            .toList();
    }

    @Override
    public Map<Category, Double> revenueByCategory() {
        return orders.stream()
            .collect(Collectors.groupingBy(
                Order::category,
                Collectors.summingDouble(Order::totalSales)
            ));
    }

    @Override
    public Set<String> suspiciousCustomers() {
        return orders.stream()
            .filter(order -> order.status() == Status.CANCELLED)
            .filter(order -> order.totalSales() < MIN_SUSPICIOUS_TOTAL_SALES)
            .collect(Collectors.groupingBy(Order::customerName, Collectors.counting()))
            .entrySet().stream()
            .filter(entry -> entry.getValue() > SUSPICIOUS_ORDER_THRESHOLD)
            .map(Map.Entry::getKey)
            .collect(Collectors.toUnmodifiableSet());
    }

    @Override
    public Map<Category, PaymentMethod> mostUsedPaymentMethodForCategory() {
        if (orders.isEmpty()) {
            return Map.of();
        }
        Map<Category, Map<PaymentMethod, Long>> categoryPaymentCounts = orders.stream()
            .collect(Collectors.groupingBy(
                Order::category,
                Collectors.groupingBy(
                    Order::paymentMethod,
                    Collectors.counting()
                )
            ));
        Map<Category, PaymentMethod> result = new EnumMap<>(Category.class);
        Comparator<Map.Entry<PaymentMethod, Long>> paymentMethodComparator = (e1, e2) -> {
            int countCompare = e1.getValue().compareTo(e2.getValue());
            if (countCompare != 0) {
                return countCompare;
            }
            return e2.getKey().name().compareTo(e1.getKey().name());
        };

        categoryPaymentCounts.forEach((category, paymentMap) -> {
            paymentMap.entrySet().stream()
                .max(paymentMethodComparator)
                .map(Map.Entry::getKey)
                .ifPresent(mostUsed -> result.put(category, mostUsed));
        });

        return result;
    }

    @Override
    public String locationWithMostOrders() {
        if (orders.isEmpty()) {
            return null;
        }

        Optional<Map.Entry<String, Long>> result = orders.stream()
            .collect(Collectors.groupingBy(Order::customerLocation, Collectors.counting()))
            .entrySet().stream()
            .max(Comparator
                .comparingLong(Map.Entry<String, Long>::getValue)
                .thenComparing(Map.Entry::getKey, Comparator.reverseOrder()));

        return result.map(Map.Entry::getKey).orElse(null);
    }

    @Override
    public Map<Category, Map<Status, Long>> groupByCategoryAndStatus() {
        if (orders.isEmpty()) {
            return Map.of();
        }

        return orders.stream()
            .collect(Collectors.groupingBy(
                Order::category,
                Collectors.groupingBy(
                    Order::status,
                    Collectors.counting()
                )
            ));
    }
}