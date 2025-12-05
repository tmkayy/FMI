package bg.sofia.uni.fmi.mjt.imagekit.algorithm.detection;

import bg.sofia.uni.fmi.mjt.imagekit.algorithm.grayscale.LuminosityGrayscale;
import org.junit.jupiter.api.Test;
import java.awt.Color;
import java.awt.image.BufferedImage;

import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.junit.jupiter.api.Assertions.assertTrue;

class SobelEdgeDetectionTest {

    @Test
    void testProcessNullImageThrowsException() {
        SobelEdgeDetection sobel = new SobelEdgeDetection(new LuminosityGrayscale());
        assertThrows(IllegalArgumentException.class, () -> sobel.process(null));
    }

    @Test
    void testProcessUniformImageHasNoEdges() {
        SobelEdgeDetection sobel = new SobelEdgeDetection(new LuminosityGrayscale());
        BufferedImage image = new BufferedImage(10, 10, BufferedImage.TYPE_INT_RGB);

        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                image.setRGB(x, y, new Color(128, 128, 128).getRGB());
            }
        }

        BufferedImage result = sobel.process(image);
        int edgeValue = (result.getRGB(5, 5) >> 16) & 0xFF;
        assertTrue(edgeValue < 10);
    }

    @Test
    void testProcessVerticalEdgeDetectsEdge() {
        SobelEdgeDetection sobel = new SobelEdgeDetection(new LuminosityGrayscale());
        BufferedImage image = new BufferedImage(10, 10, BufferedImage.TYPE_INT_RGB);

        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                if (x < 5) {
                    image.setRGB(x, y, Color.BLACK.getRGB());
                } else {
                    image.setRGB(x, y, Color.WHITE.getRGB());
                }
            }
        }

        BufferedImage result = sobel.process(image);
        int edgeValue = (result.getRGB(4, 5) >> 16) & 0xFF;
        assertTrue(edgeValue > 100);
    }
}