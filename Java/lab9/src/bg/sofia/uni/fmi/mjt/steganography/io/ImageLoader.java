package bg.sofia.uni.fmi.mjt.steganography.io;

import bg.sofia.uni.fmi.mjt.steganography.dto.ImagePair;
import bg.sofia.uni.fmi.mjt.steganography.dto.StegoImage;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.io.UncheckedIOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class ImageLoader {

    public static List<ImagePair> loadImagePairs(String coverDir, String secretDir) throws IOException {
        Path coverPath = Paths.get(coverDir);
        Path secretPath = Paths.get(secretDir);

        String[] coverFiles = DirectoryManager.getSortedPNGFiles(coverPath);
        String[] secretFiles = DirectoryManager.getSortedPNGFiles(secretPath);

        if (coverFiles.length != secretFiles.length) {
            throw new IllegalArgumentException("Number of cover and secret images must match");
        }

        List<ImagePair> pairs = new ArrayList<>();

        for (int i = 0; i < coverFiles.length; i++) {
            BufferedImage coverImage = loadImage(coverPath.resolve(coverFiles[i]));
            BufferedImage secretImage = loadImage(secretPath.resolve(secretFiles[i]));
            pairs.add(new ImagePair(coverImage, secretImage, coverFiles[i]));
        }

        return pairs;
    }

    public static List<StegoImage> loadStegoImages(String sourceDir) throws IOException {
        Path sourcePath = Paths.get(sourceDir);
        String[] sourceFiles = DirectoryManager.getSortedPNGFiles(sourcePath);

        List<StegoImage> images = new ArrayList<>();

        for (String fileName : sourceFiles) {
            BufferedImage image = loadImage(sourcePath.resolve(fileName));
            images.add(new StegoImage(image, fileName));
        }

        return images;
    }

    private static BufferedImage loadImage(Path imagePath) {
        try {
            BufferedImage image = ImageIO.read(imagePath.toFile());
            if (image == null) {
                throw new IOException("Failed to load image: " + imagePath);
            }
            return image;
        } catch (IOException e) {
            throw new UncheckedIOException("Failed to load image: " + imagePath, e);
        }
    }
}