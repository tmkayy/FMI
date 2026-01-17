package bg.sofia.uni.fmi.mjt.steganography.algorithm;

import java.awt.image.BufferedImage;

public class SteganographyAlgorithm {
    private static final int EMBED_METADATA_PIXELS = 8;
    private static final int PIXELS_PER_DIMENSION = 4;
    private static final int BITS_PER_DIMENSION = 12;
    private static final int BITS_PER_PIXEL = 3;
    private static final int COLOR_COMPONENTS = 3;

    private static final int RED_SHIFT = 16;
    private static final int GREEN_SHIFT = 8;
    private static final int BLUE_SHIFT = 0;

    private static final int THREE_MSB_SHIFT = 5;
    private static final int RGB_COMPONENT_MASK = 0xFF;
    private static final int THREE_BIT_MASK = 0x07;
    private static final int LSB_CLEAR_MASK = 0xFE;
    private static final int LSB_MASK = 0x01;

    private static final int BIT_POSITION_1 = 2;
    private static final int BIT_POSITION_2 = 1;
    private static final int BIT_POSITION_3 = 0;

    private static final int BUFFERED_IMAGE_TYPE = BufferedImage.TYPE_INT_RGB;

    public boolean canEmbed(BufferedImage cover, BufferedImage secret) {
        int coverPixels = cover.getWidth() * cover.getHeight();
        int secretPixels = secret.getWidth() * secret.getHeight();
        return coverPixels >= secretPixels + EMBED_METADATA_PIXELS;
    }

    public BufferedImage embedImage(BufferedImage cover, BufferedImage secret) {
        if (!canEmbed(cover, secret)) {
            throw new IllegalArgumentException("Cannot embed secret image into cover image");
        }

        BufferedImage stegoImage = copyImage(cover);
        embedDimension(stegoImage, 0, secret.getWidth());
        embedDimension(stegoImage, PIXELS_PER_DIMENSION, secret.getHeight());
        embedSecretData(stegoImage, secret);
        return stegoImage;
    }

    public BufferedImage extractImage(BufferedImage stegoImage) {
        int secretWidth = extractDimension(stegoImage, 0);
        int secretHeight = extractDimension(stegoImage, PIXELS_PER_DIMENSION);
        BufferedImage secretImage = createImage(secretWidth, secretHeight);
        extractSecretData(stegoImage, secretImage);
        return secretImage;
    }

    private BufferedImage copyImage(BufferedImage source) {
        BufferedImage copy = new BufferedImage(
            source.getWidth(),
            source.getHeight(),
            BUFFERED_IMAGE_TYPE
        );

        for (int y = 0; y < source.getHeight(); y++) {
            for (int x = 0; x < source.getWidth(); x++) {
                copy.setRGB(x, y, source.getRGB(x, y));
            }
        }

        return copy;
    }

    private BufferedImage createImage(int width, int height) {
        return new BufferedImage(width, height, BUFFERED_IMAGE_TYPE);
    }

    private void embedDimension(BufferedImage image, int startPixel, int dimension) {
        for (int i = 0; i < PIXELS_PER_DIMENSION; i++) {
            processPixelForDimension(image, startPixel + i, dimension, i);
        }
    }

    private void processPixelForDimension(BufferedImage image, int pixelIndex, int dimension, int bitOffset) {
        int x = pixelIndex % image.getWidth();
        int y = pixelIndex / image.getWidth();
        if (y >= image.getHeight()) {
            return;
        }

        int pixel = image.getRGB(x, y);
        int bits = extractBitsFromDimension(dimension, bitOffset);
        int newPixel = embedBitsInPixel(pixel, bits);
        image.setRGB(x, y, newPixel);
    }

    private int extractBitsFromDimension(int dimension, int pixelIndex) {
        int shiftAmount = BITS_PER_DIMENSION - BITS_PER_PIXEL - (pixelIndex * BITS_PER_PIXEL);
        return (dimension >> shiftAmount) & THREE_BIT_MASK;
    }

    private int embedBitsInPixel(int pixel, int bits) {
        int r = extractColorComponent(pixel, RED_SHIFT);
        int g = extractColorComponent(pixel, GREEN_SHIFT);
        int b = extractColorComponent(pixel, BLUE_SHIFT);

        r = embedBitInComponent(r, bits, BIT_POSITION_1);
        g = embedBitInComponent(g, bits, BIT_POSITION_2);
        b = embedBitInComponent(b, bits, BIT_POSITION_3);

        return combineColorComponents(r, g, b);
    }

    private int extractColorComponent(int pixel, int shift) {
        return (pixel >> shift) & RGB_COMPONENT_MASK;
    }

    private int embedBitInComponent(int component, int bits, int bitPosition) {
        return (component & LSB_CLEAR_MASK) | ((bits >> bitPosition) & LSB_MASK);
    }

    private int combineColorComponents(int r, int g, int b) {
        return (r << RED_SHIFT) | (g << GREEN_SHIFT) | (b << BLUE_SHIFT);
    }

    private void embedSecretData(BufferedImage stegoImage, BufferedImage secret) {
        int pixelIndex = EMBED_METADATA_PIXELS;
        for (int y = 0; y < secret.getHeight(); y++) {
            for (int x = 0; x < secret.getWidth(); x++) {
                if (pixelIndex >= stegoImage.getWidth() * stegoImage.getHeight()) {
                    return;
                }
                embedPixelSecretData(stegoImage, secret, x, y, pixelIndex);
                pixelIndex++;
            }
        }
    }

    private void embedPixelSecretData(BufferedImage stegoImage, BufferedImage secret,
                                      int secretX, int secretY, int stegoPixelIndex) {
        int secretPixel = secret.getRGB(secretX, secretY);
        int r = extractColorComponent(secretPixel, RED_SHIFT);
        int g = extractColorComponent(secretPixel, GREEN_SHIFT);
        int b = extractColorComponent(secretPixel, BLUE_SHIFT);

        int average = (r + g + b) / COLOR_COMPONENTS;
        int msb3 = (average >> THREE_MSB_SHIFT) & THREE_BIT_MASK;

        int stegoX = stegoPixelIndex % stegoImage.getWidth();
        int stegoY = stegoPixelIndex / stegoImage.getWidth();
        int stegoPixel = stegoImage.getRGB(stegoX, stegoY);
        int newPixel = embedBitsInPixel(stegoPixel, msb3);
        stegoImage.setRGB(stegoX, stegoY, newPixel);
    }

    private int extractDimension(BufferedImage image, int startPixel) {
        int dimension = 0;
        for (int i = 0; i < PIXELS_PER_DIMENSION; i++) {
            dimension = (dimension << BITS_PER_PIXEL) | extractPixelBits(image, startPixel + i);
        }
        return dimension;
    }

    private int extractPixelBits(BufferedImage image, int pixelIndex) {
        int x = pixelIndex % image.getWidth();
        int y = pixelIndex / image.getWidth();
        if (y >= image.getHeight()) {
            return 0;
        }

        int pixel = image.getRGB(x, y);
        return extractBitsFromPixel(pixel);
    }

    private int extractBitsFromPixel(int pixel) {
        int r = (pixel >> RED_SHIFT) & LSB_MASK;
        int g = (pixel >> GREEN_SHIFT) & LSB_MASK;
        int b = (pixel >> BLUE_SHIFT) & LSB_MASK;
        return (r << BIT_POSITION_1) | (g << BIT_POSITION_2) | b;
    }

    private void extractSecretData(BufferedImage stegoImage, BufferedImage secretImage) {
        int pixelIndex = EMBED_METADATA_PIXELS;
        for (int y = 0; y < secretImage.getHeight(); y++) {
            for (int x = 0; x < secretImage.getWidth(); x++) {
                if (pixelIndex >= stegoImage.getWidth() * stegoImage.getHeight()) {
                    return;
                }
                extractPixelSecretData(stegoImage, secretImage, x, y, pixelIndex);
                pixelIndex++;
            }
        }
    }

    private void extractPixelSecretData(BufferedImage stegoImage, BufferedImage secretImage,
                                        int secretX, int secretY, int stegoPixelIndex) {
        int stegoX = stegoPixelIndex % stegoImage.getWidth();
        int stegoY = stegoPixelIndex / stegoImage.getWidth();
        int stegoPixel = stegoImage.getRGB(stegoX, stegoY);

        int extractedBits = extractBitsFromPixel(stegoPixel);
        int grayValue = extractedBits << THREE_MSB_SHIFT;
        int secretPixel = combineColorComponents(grayValue, grayValue, grayValue);
        secretImage.setRGB(secretX, secretY, secretPixel);
    }
}