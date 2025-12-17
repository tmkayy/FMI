package bg.sofia.uni.fmi.mjt.order.analyzer;

import bg.sofia.uni.fmi.mjt.order.domain.*;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

import java.time.LocalDate;
import java.util.List;

public class OrderAnalyzerImplTest {

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
        var result = analyzer.dateWithMostOrders();

        assertEquals(LocalDate.of(2025, 3, 14), result.getKey());
        assertEquals(2, result.getValue());
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
    void testMostUsedPaymentMethodForCategoryTie() {
        List<Order> orders = List.of(
            new Order("1", LocalDate.now(), "A", Category.ELECTRONICS, 100, 1, 100, "C1", "L1",
                PaymentMethod.CREDIT_CARD, Status.COMPLETED),
            new Order("2", LocalDate.now(), "B", Category.ELECTRONICS, 100, 1, 100, "C2", "L2",
                PaymentMethod.PAYPAL, Status.COMPLETED)
        );

        OrderAnalyzer analyzer = new OrderAnalyzerImpl(orders);
        var result = analyzer.mostUsedPaymentMethodForCategory();

        assertEquals(PaymentMethod.CREDIT_CARD, result.get(Category.ELECTRONICS));
    }
}