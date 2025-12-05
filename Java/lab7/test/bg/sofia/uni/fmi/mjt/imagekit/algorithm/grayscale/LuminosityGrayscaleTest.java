package bg.sofia.uni.fmi.mjt.imagekit.algorithm.grayscale;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;

import java.awt.Color;
import java.awt.image.BufferedImage;

import static org.junit.jupiter.api.Assertions.*;

class LuminosityGrayscaleTest {

    @Test
    void testProcessNullImageThrowsException() {
        LuminosityGrayscale grayscale = new LuminosityGrayscale();
        assertThrows(IllegalArgumentException.class, () -> grayscale.process(null));
    }

    @Test
    void testProcessImageReturnsCorrectDimensions() {
        LuminosityGrayscale grayscale = new LuminosityGrayscale();
        BufferedImage image = new BufferedImage(50, 30, BufferedImage.TYPE_INT_RGB);

        BufferedImage result = grayscale.process(image);

        assertEquals(50, result.getWidth());
        assertEquals(30, result.getHeight());
    }

    @ParameterizedTest
    @CsvSource({
        "0, 0, 0, 0",      // Black
        "255, 255, 255, 255", // White
        "255, 0, 0, 54",    // Red
        "0, 255, 0, 184",   // Green
        "0, 0, 255, 18"     // Blue
    })
    void testProcessDifferentColors(int r, int g, int b, int expected) {
        LuminosityGrayscale grayscale = new LuminosityGrayscale();
        BufferedImage image = new BufferedImage(1, 1, BufferedImage.TYPE_INT_RGB);
        image.setRGB(0, 0, new Color(r, g, b).getRGB());

        BufferedImage result = grayscale.process(image);
        int grayValue = (result.getRGB(0, 0) >> 16) & 0xFF;

        assertEquals(expected, grayValue);
    }

    @Test
    void testProcessGrayscaleImageStaysSame() {
        LuminosityGrayscale grayscale = new LuminosityGrayscale();
        BufferedImage image = new BufferedImage(10, 10, BufferedImage.TYPE_INT_RGB);

        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                image.setRGB(x, y, new Color(100, 100, 100).getRGB());
            }
        }

        BufferedImage result = grayscale.process(image);
        int grayValue = (result.getRGB(0, 0) >> 16) & 0xFF;

        assertEquals(100, grayValue);
    }

    @Test
    void testResultImageIsGrayscale() {
        LuminosityGrayscale grayscale = new LuminosityGrayscale();
        BufferedImage image = new BufferedImage(5, 5, BufferedImage.TYPE_INT_RGB);
        image.setRGB(0, 0, Color.RED.getRGB());

        BufferedImage result = grayscale.process(image);
        int rgb = result.getRGB(0, 0);
        int r = (rgb >> 16) & 0xFF;
        int g = (rgb >> 8) & 0xFF;
        int b = rgb & 0xFF;

        assertEquals(r, g);
        assertEquals(g, b);
    }
}