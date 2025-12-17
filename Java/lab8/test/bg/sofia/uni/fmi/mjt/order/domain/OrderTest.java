package bg.sofia.uni.fmi.mjt.order.domain;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class OrderTest {

    @Test
    void testOrderParsingWithDifferentFormats() {
        String line1 = "ORD001,14-03-25,Running Shoes,Footwear,60,3,180,Emma Clark,New York,Debit Card,Cancelled";
        Order order1 = Order.of(line1);
        assertEquals(Category.FOOTWEAR, order1.category());
        assertEquals(PaymentMethod.DEBIT_CARD, order1.paymentMethod());
        assertEquals(Status.CANCELLED, order1.status());

        String line2 = "ORD002,14-03-25,USB-C Cable,Electronics,25.50,2,51,John Smith,SF,Credit Card,Pending";
        Order order2 = Order.of(line2);
        assertEquals(Category.ELECTRONICS, order2.category());
        assertEquals(PaymentMethod.CREDIT_CARD, order2.paymentMethod());
        assertEquals(Status.PENDING, order2.status());

        String line3 = "ORD003,14-03-25,Book,Books,0,1,0,John,NYC,Credit Card,Pending";
        Order order3 = Order.of(line3);
        assertEquals(Category.BOOKS, order3.category());
        assertEquals(0.0, order3.price(), 0.001);
        assertEquals(0.0, order3.totalSales(), 0.001);
    }

    @Test
    void testOrderParsingWithSpacesAndTrim() {
        String line = "  ORD001  ,  14-03-25  ,  Laptop  ,  ELECTRONICS  ,  999.99  ,  1  ,  999.99  ,  John Doe  ,  New York  ,  CREDIT_CARD  ,  COMPLETED  ";
        Order order = Order.of(line);
        assertEquals("ORD001", order.id());
        assertEquals("Laptop", order.product());
        assertEquals("John Doe", order.customerName());
    }

    @Test
    void testOrderParsingInvalidNumberFormat() {
        String line = "ORD001,14-03-25,Laptop,ELECTRONICS,invalid,1,999.99,John Doe,NY,CREDIT_CARD,COMPLETED";
        assertThrows(IllegalArgumentException.class, () -> Order.of(line));
    }

    @Test
    void testOrderParsingInvalidEnum() {
        String line = "ORD001,14-03-25,Laptop,INVALID_CATEGORY,999.99,1,999.99,John Doe,NY,CREDIT_CARD,COMPLETED";
        assertThrows(IllegalArgumentException.class, () -> Order.of(line));
    }

    @Test
    void testOrderParsingWrongFieldCount() {
        String line = "ORD001,14-03-25,Laptop,ELECTRONICS,999.99";
        assertThrows(IllegalArgumentException.class, () -> Order.of(line));
    }

    @Test
    void testOrderParsingEmptyString() {
        assertThrows(IllegalArgumentException.class, () -> Order.of(""));
    }

    @Test
    void testOrderParsingBlankString() {
        assertThrows(IllegalArgumentException.class, () -> Order.of("   "));
    }

    @Test
    void testOrderParsingNull() {
        assertThrows(IllegalArgumentException.class, () -> Order.of(null));
    }
}