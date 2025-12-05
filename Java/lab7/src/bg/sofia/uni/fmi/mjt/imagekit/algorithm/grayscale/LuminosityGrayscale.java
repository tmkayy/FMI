package bg.sofia.uni.fmi.mjt.imagekit.algorithm.grayscale;

import java.awt.Color;
import java.awt.image.BufferedImage;

public class LuminosityGrayscale implements GrayscaleAlgorithm {
    private static final int RGB_MAX = 255;
    private static final double RED_COEFF = 0.21;
    private static final double GREEN_COEFF = 0.72;
    private static final double BLUE_COEFF = 0.07;

    public LuminosityGrayscale() {
    }

    @Override
    public BufferedImage process(BufferedImage image) {
        if (image == null) {
            throw new IllegalArgumentException("Image must not be null");
        }

        int width = image.getWidth();
        int height = image.getHeight();
        int imageType = BufferedImage.TYPE_INT_RGB;
        BufferedImage result = new BufferedImage(width, height, imageType);

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                Color color = new Color(image.getRGB(x, y));
                int red = color.getRed();
                int green = color.getGreen();
                int blue = color.getBlue();

                double grayValue = RED_COEFF * red + GREEN_COEFF * green + BLUE_COEFF * blue;
                int gray = (int) Math.round(grayValue);
                gray = Math.max(0, Math.min(RGB_MAX, gray));

                Color grayColor = new Color(gray, gray, gray);
                result.setRGB(x, y, grayColor.getRGB());
            }
        }

        return result;
    }
}
