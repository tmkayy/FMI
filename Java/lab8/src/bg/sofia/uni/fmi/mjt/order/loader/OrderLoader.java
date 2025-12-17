package bg.sofia.uni.fmi.mjt.order.loader;

import bg.sofia.uni.fmi.mjt.order.domain.Order;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.Reader;
import java.util.ArrayList;
import java.util.List;

public class OrderLoader {

    public static List<Order> load(Reader reader) {
        if (reader == null) {
            throw new IllegalArgumentException("Reader cannot be null");
        }

        List<Order> orders = new ArrayList<>();

        try (BufferedReader br = new BufferedReader(reader)) {
            br.readLine();

            String line;
            while ((line = br.readLine()) != null) {
                if (line.trim().isEmpty()) {
                    continue;
                }

                try {
                    Order order = Order.of(line);
                    orders.add(order);
                } catch (IllegalArgumentException e) {
                    System.err.println("Skipping invalid line: " + e.getMessage());
                }
            }
        } catch (IOException e) {
            throw new RuntimeException("Error reading from reader", e);
        }

        return orders;
    }
}