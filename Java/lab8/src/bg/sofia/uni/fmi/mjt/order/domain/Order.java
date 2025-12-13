package bg.sofia.uni.fmi.mjt.order.domain;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public record Order(String id, LocalDate date, String product, Category category,
                    double price, int quantity, double totalSales,
                    String customerName, String customerLocation,
                    PaymentMethod paymentMethod, Status status) {

    private static final DateTimeFormatter DATE_FORMATTER =
        DateTimeFormatter.ofPattern("dd-MM-yy");

    private static final int EXPECTED_FIELD_COUNT = 11;
    private static final int ID_INDEX = 0;
    private static final int DATE_INDEX = 1;
    private static final int PRODUCT_INDEX = 2;
    private static final int CATEGORY_INDEX = 3;
    private static final int PRICE_INDEX = 4;
    private static final int QUANTITY_INDEX = 5;
    private static final int TOTAL_SALES_INDEX = 6;
    private static final int CUSTOMER_NAME_INDEX = 7;
    private static final int CUSTOMER_LOCATION_INDEX = 8;
    private static final int PAYMENT_METHOD_INDEX = 9;
    private static final int STATUS_INDEX = 10;

    public static Order of(String line) {
        validateLine(line);
        String[] parts = splitLine(line);
        return createOrderFromParts(parts);
    }

    private static void validateLine(String line) {
        if (line == null || line.trim().isEmpty()) {
            throw new IllegalArgumentException("Line cannot be null or empty");
        }
    }

    private static String[] splitLine(String line) {
        String[] parts = line.split(",", -1);
        if (parts.length != EXPECTED_FIELD_COUNT) {
            throw new IllegalArgumentException("Invalid CSV format. Expected " +
                EXPECTED_FIELD_COUNT + " fields, got " + parts.length);
        }
        return parts;
    }

    private static Order createOrderFromParts(String[] parts) {
        try {
            String id = parts[ID_INDEX].trim();
            LocalDate date = parseDate(parts[DATE_INDEX]);
            String product = parts[PRODUCT_INDEX].trim();
            Category category = parseCategory(parts[CATEGORY_INDEX]);
            double price = parseDouble(parts[PRICE_INDEX]);
            int quantity = parseInt(parts[QUANTITY_INDEX]);
            double totalSales = parseDouble(parts[TOTAL_SALES_INDEX]);
            String customerName = parts[CUSTOMER_NAME_INDEX].trim();
            String customerLocation = parts[CUSTOMER_LOCATION_INDEX].trim();
            PaymentMethod paymentMethod = parsePaymentMethod(parts[PAYMENT_METHOD_INDEX]);
            Status status = parseStatus(parts[STATUS_INDEX]);

            return new Order(id, date, product, category, price, quantity,
                totalSales, customerName, customerLocation, paymentMethod, status);
        } catch (NumberFormatException e) {
            throw new IllegalArgumentException("Invalid number format", e);
        } catch (IllegalArgumentException e) {
            throw new IllegalArgumentException("Invalid enum value", e);
        } catch (Exception e) {
            throw new IllegalArgumentException("Error parsing line", e);
        }
    }

    private static LocalDate parseDate(String dateStr) {
        return LocalDate.parse(dateStr.trim(), DATE_FORMATTER);
    }

    private static Category parseCategory(String categoryStr) {
        String normalized = categoryStr.trim().toUpperCase()
            .replace(" ", "_")
            .replace("-", "_");
        return Category.valueOf(normalized);
    }

    private static double parseDouble(String doubleStr) {
        return Double.parseDouble(doubleStr.trim());
    }

    private static int parseInt(String intStr) {
        return Integer.parseInt(intStr.trim());
    }

    private static PaymentMethod parsePaymentMethod(String paymentMethodStr) {
        String normalized = paymentMethodStr.trim().toUpperCase()
            .replace(" ", "_")
            .replace("-", "_");
        return PaymentMethod.valueOf(normalized);
    }

    private static Status parseStatus(String statusStr) {
        String normalized = statusStr.trim().toUpperCase()
            .replace(" ", "_")
            .replace("-", "_");
        return Status.valueOf(normalized);
    }
}