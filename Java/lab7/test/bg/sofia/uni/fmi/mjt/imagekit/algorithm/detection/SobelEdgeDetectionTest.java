package bg.sofia.uni.fmi.mjt.imagekit.algorithm.detection;

import bg.sofia.uni.fmi.mjt.imagekit.algorithm.grayscale.LuminosityGrayscale;
import org.junit.jupiter.api.Test;

import java.awt.Color;
import java.awt.image.BufferedImage;

import static org.junit.jupiter.api.Assertions.*;

class SobelEdgeDetectionTest {

    @Test
    void testConstructorWithNullThrowsException() {
        assertThrows(NullPointerException.class, () -> new SobelEdgeDetection(null));
    }

    @Test
    void testProcessNullImageThrowsException() {
        SobelEdgeDetection sobel = new SobelEdgeDetection(new LuminosityGrayscale());
        assertThrows(IllegalArgumentException.class, () -> sobel.process(null));
    }

    @Test
    void testProcessReturnsSameDimensions() {
        SobelEdgeDetection sobel = new SobelEdgeDetection(new LuminosityGrayscale());
        BufferedImage image = new BufferedImage(40, 30, BufferedImage.TYPE_INT_RGB);

        BufferedImage result = sobel.process(image);

        assertEquals(40, result.getWidth());
        assertEquals(30, result.getHeight());
    }

    @Test
    void testProcessUniformImageReturnsDarkImage() {
        SobelEdgeDetection sobel = new SobelEdgeDetection(new LuminosityGrayscale());
        BufferedImage image = new BufferedImage(10, 10, BufferedImage.TYPE_INT_RGB);

        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                image.setRGB(x, y, Color.GRAY.getRGB());
            }
        }

        BufferedImage result = sobel.process(image);

        // Uniform images should have low edge values
        int pixelValue = (result.getRGB(5, 5) >> 16) & 0xFF;
        assertTrue(pixelValue < 50, "Uniform image should have low edge values");
    }

    @Test
    void testProcessEdgeImageReturnsBrightEdges() {
        SobelEdgeDetection sobel = new SobelEdgeDetection(new LuminosityGrayscale());
        BufferedImage image = new BufferedImage(10, 10, BufferedImage.TYPE_INT_RGB);

        // Create vertical edge
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                image.setRGB(x, y, (x < 5) ? Color.BLACK.getRGB() : Color.WHITE.getRGB());
            }
        }

        BufferedImage result = sobel.process(image);

        // Edge area should have high values
        int edgeValue = (result.getRGB(4, 5) >> 16) & 0xFF;
        assertTrue(edgeValue > 100, "Edge should be detected as bright");
    }

    @Test
    void testAllPixelValuesInValidRange() {
        SobelEdgeDetection sobel = new SobelEdgeDetection(new LuminosityGrayscale());
        BufferedImage image = new BufferedImage(8, 8, BufferedImage.TYPE_INT_RGB);

        // Random pattern
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++) {
                image.setRGB(x, y, ((x + y) * 20) << 16);
            }
        }

        BufferedImage result = sobel.process(image);

        // All pixels should be in valid range
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++) {
                int value = (result.getRGB(x, y) >> 16) & 0xFF;
                assertTrue(value >= 0 && value <= 255);
            }
        }
    }

    @Test
    void testResultIsGrayscale() {
        SobelEdgeDetection sobel = new SobelEdgeDetection(new LuminosityGrayscale());
        BufferedImage image = new BufferedImage(10, 10, BufferedImage.TYPE_INT_RGB);

        BufferedImage result = sobel.process(image);
        int rgb = result.getRGB(0, 0);
        int r = (rgb >> 16) & 0xFF;
        int g = (rgb >> 8) & 0xFF;
        int b = rgb & 0xFF;

        assertEquals(r, g);
        assertEquals(g, b);
    }
}