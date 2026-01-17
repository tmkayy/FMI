package bg.sofia.uni.fmi.mjt.steganography;

import bg.sofia.uni.fmi.mjt.steganography.algorithm.SteganographyAlgorithm;
import bg.sofia.uni.fmi.mjt.steganography.dto.ImagePair;
import bg.sofia.uni.fmi.mjt.steganography.dto.ProcessedImage;
import bg.sofia.uni.fmi.mjt.steganography.dto.StegoImage;
import bg.sofia.uni.fmi.mjt.steganography.io.DirectoryManager;
import bg.sofia.uni.fmi.mjt.steganography.io.ImageLoader;
import bg.sofia.uni.fmi.mjt.steganography.io.ImageSaver;
import bg.sofia.uni.fmi.mjt.steganography.threading.TaskManager;

import java.awt.image.BufferedImage;
import java.util.List;

public class ImageCodecImpl implements ImageCodec {
    private final SteganographyAlgorithm algorithm;
    private final TaskManager taskManager;

    public ImageCodecImpl() {
        this.algorithm = new SteganographyAlgorithm();
        this.taskManager = new TaskManager();
    }

    @Override
    public void embedPNGImages(String coverSourceDirectory, String secretSourceDirectory, String outputDirectory) {
        DirectoryManager.createDirectoryIfNotExists(outputDirectory);

        try {
            // Load images
            List<ImagePair> imagePairs = ImageLoader.loadImagePairs(
                coverSourceDirectory,
                secretSourceDirectory
            );

            // Process images in parallel
            List<ProcessedImage> processedImages = taskManager.processInParallel(
                imagePairs,
                pair -> {
                    BufferedImage stegoImage = algorithm.embedImage(pair.coverImage(), pair.secretImage());
                    return new ProcessedImage(stegoImage, pair.fileName());
                }
            );

            // Save processed images
            ImageSaver.saveImages(processedImages, outputDirectory);

        } catch (Exception e) {
            throw new RuntimeException("Error embedding images", e);
        }
    }

    @Override
    public void extractPNGImages(String sourceDirectory, String outputDirectory) {
        DirectoryManager.createDirectoryIfNotExists(outputDirectory);

        try {
            // Load stego images
            List<StegoImage> stegoImages = ImageLoader.loadStegoImages(sourceDirectory);

            // Extract images in parallel
            List<ProcessedImage> extractedImages = taskManager.processInParallel(
                stegoImages,
                stego -> {
                    BufferedImage secretImage = algorithm.extractImage(stego.image());
                    return new ProcessedImage(secretImage, stego.fileName());
                }
            );

            // Save extracted images
            ImageSaver.saveImages(extractedImages, outputDirectory);

        } catch (Exception e) {
            throw new RuntimeException("Error extracting images", e);
        }
    }
}