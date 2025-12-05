package bg.sofia.uni.fmi.mjt.imagekit.algorithm.grayscale;

import org.junit.jupiter.api.Test;
import java.awt.Color;
import java.awt.image.BufferedImage;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

class LuminosityGrayscaleTest {

    @Test
    void testProcessNullImageThrowsException() {
        LuminosityGrayscale grayscale = new LuminosityGrayscale();
        assertThrows(IllegalArgumentException.class, () -> grayscale.process(null));
    }

    @Test
    void testProcessBlackImageReturnsBlack() {
        LuminosityGrayscale grayscale = new LuminosityGrayscale();
        BufferedImage image = new BufferedImage(10, 10, BufferedImage.TYPE_INT_RGB);

        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                image.setRGB(x, y, Color.BLACK.getRGB());
            }
        }

        BufferedImage result = grayscale.process(image);
        int grayValue = (result.getRGB(0, 0) >> 16) & 0xFF;
        assertEquals(0, grayValue);
    }

    @Test
    void testProcessWhiteImageReturnsWhite() {
        LuminosityGrayscale grayscale = new LuminosityGrayscale();
        BufferedImage image = new BufferedImage(10, 10, BufferedImage.TYPE_INT_RGB);

        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                image.setRGB(x, y, Color.WHITE.getRGB());
            }
        }

        BufferedImage result = grayscale.process(image);
        int grayValue = (result.getRGB(0, 0) >> 16) & 0xFF;
        assertEquals(255, grayValue);
    }

    @Test
    void testProcessRedImageCalculatesCorrectValue() {
        LuminosityGrayscale grayscale = new LuminosityGrayscale();
        BufferedImage image = new BufferedImage(1, 1, BufferedImage.TYPE_INT_RGB);
        image.setRGB(0, 0, Color.RED.getRGB());

        BufferedImage result = grayscale.process(image);
        int grayValue = (result.getRGB(0, 0) >> 16) & 0xFF;
        // 0.21*255 + 0.72*0 + 0.07*0 = 53.55 ≈ 54
        assertEquals(54, grayValue);
    }
}