package bg.sofia.uni.fmi.mjt.order.loader;

import bg.sofia.uni.fmi.mjt.order.domain.Order;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

import java.io.StringReader;
import java.util.List;

public class OrderLoaderTest {

    @Test
    void testLoadWithDifferentEnumFormats() {
        String csvData = """
            Order ID,Date,Product,Category,Price,Quantity,Total Sales,Customer Name,Customer Location,Payment Method,Status
            ORD001,14-03-25,Running Shoes,Footwear,60,3,180,Emma Clark,New York,Debit Card,Cancelled
            ORD002,14-03-25,Headphones,Electronics,100,1,100,John Doe,LA,Credit Card,Completed
            ORD003,14-03-25,Book,Books,20,2,40,Jane Smith,Chicago,PayPal,Pending
            """;

        List<Order> orders = OrderLoader.load(new StringReader(csvData));
        assertEquals(3, orders.size());
    }

    @Test
    void testLoadWithEmptyLines() {
        String csvData = """
            Order ID,Date,Product,Category,Price,Quantity,Total Sales,Customer Name,Customer Location,Payment Method,Status
            
            ORD001,14-03-25,Laptop,ELECTRONICS,999.99,1,999.99,John Doe,NY,CREDIT_CARD,COMPLETED
            
            
            ORD002,15-03-25,T-Shirt,CLOTHING,19.99,2,39.98,Jane Smith,LA,PAYPAL,PENDING
            """;

        List<Order> orders = OrderLoader.load(new StringReader(csvData));
        assertEquals(2, orders.size());
    }

    @Test
    void testLoadWithInvalidLineInMiddle() {
        String csvData = """
            Order ID,Date,Product,Category,Price,Quantity,Total Sales,Customer Name,Customer Location,Payment Method,Status
            ORD001,14-03-25,Laptop,ELECTRONICS,999.99,1,999.99,John Doe,NY,CREDIT_CARD,COMPLETED
            INVALID_DATA
            ORD002,15-03-25,T-Shirt,CLOTHING,19.99,2,39.98,Jane Smith,LA,PAYPAL,PENDING
            """;

        List<Order> orders = OrderLoader.load(new StringReader(csvData));
        assertEquals(2, orders.size());
    }

    @Test
    void testLoadNullReaderThrows() {
        assertThrows(IllegalArgumentException.class, () -> OrderLoader.load(null));
    }

    @Test
    void testLoadEmptyFile() {
        String csvData = "";
        List<Order> orders = OrderLoader.load(new StringReader(csvData));
        assertTrue(orders.isEmpty());
    }

    @Test
    void testLoadOnlyHeader() {
        String csvData = "Order ID,Date,Product,Category,Price,Quantity,Total Sales,Customer Name,Customer Location,Payment Method,Status";
        List<Order> orders = OrderLoader.load(new StringReader(csvData));
        assertTrue(orders.isEmpty());
    }
}