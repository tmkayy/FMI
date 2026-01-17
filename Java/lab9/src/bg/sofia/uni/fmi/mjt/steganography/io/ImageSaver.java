package bg.sofia.uni.fmi.mjt.steganography.io;

import bg.sofia.uni.fmi.mjt.steganography.dto.ProcessedImage;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.util.List;

public class ImageSaver {
    private static final String IMAGE_FORMAT = "png";

    public static void saveImages(List<ProcessedImage> images, String outputDirectory) {
        for (ProcessedImage processedImage : images) {
            saveImage(processedImage.image(), outputDirectory, processedImage.fileName());
        }
    }

    public static void saveImage(BufferedImage image, String outputDir, String fileName) {
        try {
            File outputFile = new File(outputDir, fileName);
            ImageIO.write(image, IMAGE_FORMAT, outputFile);
        } catch (IOException e) {
            throw new UncheckedIOException("Failed to save image: " + fileName, e);
        }
    }
}