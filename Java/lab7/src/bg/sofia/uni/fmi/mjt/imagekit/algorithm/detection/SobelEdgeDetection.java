package bg.sofia.uni.fmi.mjt.imagekit.algorithm.detection;

import bg.sofia.uni.fmi.mjt.imagekit.algorithm.ImageAlgorithm;

import java.awt.image.BufferedImage;
import java.awt.Color;

public class SobelEdgeDetection implements EdgeDetectionAlgorithm {
    private final ImageAlgorithm grayscaleAlgorithm;
    private static final int RGB_MAX = 255;
    private static final int[][] GX_KERNEL = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    private static final int[][] GY_KERNEL = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    public SobelEdgeDetection(ImageAlgorithm grayscaleAlgorithm) {
        this.grayscaleAlgorithm = grayscaleAlgorithm;
    }

    @Override
    public BufferedImage process(BufferedImage image) {
        if (image == null) {
            throw new IllegalArgumentException("Image must not be null");
        }

        BufferedImage grayImage = grayscaleAlgorithm.process(image);
        int width = grayImage.getWidth();
        int height = grayImage.getHeight();
        BufferedImage result = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int pixelValue = calculateGradientMagnitude(grayImage, x, y, width, height);
                Color grayColor = new Color(pixelValue, pixelValue, pixelValue);
                result.setRGB(x, y, grayColor.getRGB());
            }
        }

        return result;
    }

    private int calculateGradientMagnitude(BufferedImage grayImage, int x, int y, int width, int height) {
        double gx = 0.0;
        double gy = 0.0;

        for (int ky = -1; ky <= 1; ky++) {
            for (int kx = -1; kx <= 1; kx++) {
                int pixelX = x + kx;
                int pixelY = y + ky;

                int pixelValue = 0;
                if (pixelX >= 0 && pixelX < width && pixelY >= 0 && pixelY < height) {
                    Color color = new Color(grayImage.getRGB(pixelX, pixelY));
                    pixelValue = color.getRed();
                }

                gx += pixelValue * GX_KERNEL[ky + 1][kx + 1];
                gy += pixelValue * GY_KERNEL[ky + 1][kx + 1];
            }
        }

        double magnitude = Math.sqrt(gx * gx + gy * gy);
        return Math.min(RGB_MAX, (int) Math.round(magnitude));
    }
}