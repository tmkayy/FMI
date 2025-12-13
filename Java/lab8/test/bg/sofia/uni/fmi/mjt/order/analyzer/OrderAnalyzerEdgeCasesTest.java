package bg.sofia.uni.fmi.mjt.order.analyzer;

import bg.sofia.uni.fmi.mjt.order.domain.*;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

import java.time.LocalDate;
import java.util.List;
import java.util.Map;

public class OrderAnalyzerEdgeCasesTest {

    @Test
    void testAllMethodsWithEmptyList() {
        OrderAnalyzer emptyAnalyzer = new OrderAnalyzerImpl(List.of());

        assertEquals(0, emptyAnalyzer.allOrders().size());
        assertNull(emptyAnalyzer.dateWithMostOrders());
        assertNull(emptyAnalyzer.locationWithMostOrders());
        assertTrue(emptyAnalyzer.topNMostOrderedProducts(5).isEmpty());
        assertTrue(emptyAnalyzer.revenueByCategory().isEmpty());
        assertTrue(emptyAnalyzer.suspiciousCustomers().isEmpty());
        assertTrue(emptyAnalyzer.mostUsedPaymentMethodForCategory().isEmpty());
        assertTrue(emptyAnalyzer.groupByCategoryAndStatus().isEmpty());
    }

    @Test
    void testTopNMostOrderedProductsEdgeCases() {
        List<Order> orders = List.of(
            new Order("1", LocalDate.now(), "A", Category.BOOKS, 10, 1, 10, "C1", "L1",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED),
            new Order("2", LocalDate.now(), "A", Category.BOOKS, 10, 1, 10, "C2", "L2",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED),
            new Order("3", LocalDate.now(), "B", Category.BOOKS, 10, 1, 10, "C3", "L3",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED)
        );

        OrderAnalyzer analyzer = new OrderAnalyzerImpl(orders);

        assertEquals(0, analyzer.topNMostOrderedProducts(0).size());

        assertEquals("A", analyzer.topNMostOrderedProducts(1).getFirst());

        assertEquals(2, analyzer.topNMostOrderedProducts(10).size());
    }

    @Test
    void testTopNMostOrderedProductsNegativeNThrows() {
        List<Order> orders = List.of(
            new Order("1", LocalDate.now(), "A", Category.BOOKS, 10, 1, 10, "C1", "L1",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED)
        );

        OrderAnalyzer analyzer = new OrderAnalyzerImpl(orders);

        assertThrows(IllegalArgumentException.class, () -> analyzer.topNMostOrderedProducts(-1));
    }

    @Test
    void testSuspiciousCustomersEdgeCases() {

        List<Order> threeCancelled = List.of(
            createCancelledOrder("Bob", 50),
            createCancelledOrder("Bob", 50),
            createCancelledOrder("Bob", 50)
        );

        OrderAnalyzer analyzer = new OrderAnalyzerImpl(threeCancelled);
        assertTrue(analyzer.suspiciousCustomers().isEmpty());

        List<Order> fourCancelled = List.of(
            createCancelledOrder("Bob", 50),
            createCancelledOrder("Bob", 50),
            createCancelledOrder("Bob", 50),
            createCancelledOrder("Bob", 50)
        );

        analyzer = new OrderAnalyzerImpl(fourCancelled);
        assertEquals(1, analyzer.suspiciousCustomers().size());
        assertTrue(analyzer.suspiciousCustomers().contains("Bob"));

        List<Order> cancelledOver100 = List.of(
            createCancelledOrder("Bob", 150),
            createCancelledOrder("Bob", 150),
            createCancelledOrder("Bob", 150),
            createCancelledOrder("Bob", 150)
        );

        analyzer = new OrderAnalyzerImpl(cancelledOver100);
        assertTrue(analyzer.suspiciousCustomers().isEmpty());

        List<Order> notCancelled = List.of(
            new Order("1", LocalDate.now(), "A", Category.BOOKS, 10, 1, 10, "Bob", "L1",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED),
            new Order("2", LocalDate.now(), "A", Category.BOOKS, 10, 1, 10, "Bob", "L2",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED),
            new Order("3", LocalDate.now(), "A", Category.BOOKS, 10, 1, 10, "Bob", "L3",
                PaymentMethod.CREDIT_CARD, Status.PENDING),
            new Order("4", LocalDate.now(), "A", Category.BOOKS, 10, 1, 10, "Bob", "L4",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED)
        );

        analyzer = new OrderAnalyzerImpl(notCancelled);
        assertTrue(analyzer.suspiciousCustomers().isEmpty());
    }

    private Order createCancelledOrder(String customer, double totalSales) {
        return new Order("ID", LocalDate.now(), "Product", Category.BOOKS,
            totalSales, 1, totalSales, customer, "Location",
            PaymentMethod.CREDIT_CARD, Status.CANCELLED);
    }

    @Test
    void testMostUsedPaymentMethodForCategoryTie() {
        List<Order> orders = List.of(
            new Order("1", LocalDate.now(), "A", Category.ELECTRONICS, 100, 1, 100, "C1", "L1",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED),
            new Order("2", LocalDate.now(), "B", Category.ELECTRONICS, 100, 1, 100, "C2", "L2",
                PaymentMethod.PAYPAL, Status.COMPLETED)
        );

        OrderAnalyzer analyzer = new OrderAnalyzerImpl(orders);
        Map<Category, PaymentMethod> result = analyzer.mostUsedPaymentMethodForCategory();

        assertEquals(PaymentMethod.CREDIT_CARD, result.get(Category.ELECTRONICS));
    }

    @Test
    void testLocationWithMostOrdersTieAlphabetical() {
        List<Order> orders = List.of(
            new Order("1", LocalDate.now(), "A", Category.BOOKS, 10, 1, 10, "C1", "Boston",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED),
            new Order("2", LocalDate.now(), "B", Category.BOOKS, 10, 1, 10, "C2", "Atlanta",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED)
        );

        OrderAnalyzer analyzer = new OrderAnalyzerImpl(orders);
        String location = analyzer.locationWithMostOrders();

        assertEquals("Atlanta", location);
    }

    @Test
    void testDateWithMostOrdersTieEarlierDate() {
        List<Order> orders = List.of(
            new Order("1", LocalDate.of(2025, 3, 15), "A", Category.BOOKS, 10, 1, 10, "C1", "L1",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED),
            new Order("2", LocalDate.of(2025, 3, 15), "B", Category.BOOKS, 10, 1, 10, "C2", "L2",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED),
            new Order("3", LocalDate.of(2025, 3, 14), "C", Category.BOOKS, 10, 1, 10, "C3", "L3",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED),
            new Order("4", LocalDate.of(2025, 3, 14), "D", Category.BOOKS, 10, 1, 10, "C4", "L4",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED)
        );

        OrderAnalyzer analyzer = new OrderAnalyzerImpl(orders);
        Map.Entry<LocalDate, Long> result = analyzer.dateWithMostOrders();

        assertEquals(LocalDate.of(2025, 3, 14), result.getKey());
        assertEquals(2, result.getValue());
    }

    @Test
    void testOrdersByCustomerCaseSensitive() {
        List<Order> orders = List.of(
            new Order("1", LocalDate.now(), "A", Category.BOOKS, 10, 1, 10, "John", "L1",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED),
            new Order("2", LocalDate.now(), "B", Category.BOOKS, 10, 1, 10, "JOHN", "L2",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED)
        );

        OrderAnalyzer analyzer = new OrderAnalyzerImpl(orders);

        assertEquals(1, analyzer.ordersByCustomer("John").size());
        assertEquals(1, analyzer.ordersByCustomer("JOHN").size());
        assertEquals(0, analyzer.ordersByCustomer("john").size());
    }

    @Test
    void testRevenueByCategoryWithZeroSales() {
        List<Order> orders = List.of(
            new Order("1", LocalDate.now(), "A", Category.ELECTRONICS, 0, 1, 0, "C1", "L1",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED),
            new Order("2", LocalDate.now(), "B", Category.CLOTHING, 0, 1, 0, "C2", "L2",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED)
        );

        OrderAnalyzer analyzer = new OrderAnalyzerImpl(orders);
        Map<Category, Double> revenue = analyzer.revenueByCategory();

        assertEquals(0.0, revenue.get(Category.ELECTRONICS), 0.001);
        assertEquals(0.0, revenue.get(Category.CLOTHING), 0.001);
    }

    @Test
    void testGroupByCategoryAndStatusAllStatuses() {
        List<Order> orders = List.of(
            new Order("1", LocalDate.now(), "A", Category.ELECTRONICS, 100, 1, 100, "C1", "L1",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED),
            new Order("2", LocalDate.now(), "B", Category.ELECTRONICS, 100, 1, 100, "C2", "L2",
                PaymentMethod.CREDIT_CARD, Status.PENDING),
            new Order("3", LocalDate.now(), "C", Category.ELECTRONICS, 100, 1, 100, "C3", "L3",
                PaymentMethod.CREDIT_CARD, Status.CANCELLED),
            new Order("4", LocalDate.now(), "D", Category.CLOTHING, 100, 1, 100, "C4", "L4",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED)
        );

        OrderAnalyzer analyzer = new OrderAnalyzerImpl(orders);
        Map<Category, Map<Status, Long>> result = analyzer.groupByCategoryAndStatus();

        assertTrue(result.containsKey(Category.ELECTRONICS));
        Map<Status, Long> electronicsStats = result.get(Category.ELECTRONICS);
        assertEquals(1, electronicsStats.get(Status.COMPLETED));
        assertEquals(1, electronicsStats.get(Status.PENDING));
        assertEquals(1, electronicsStats.get(Status.CANCELLED));
    }
}