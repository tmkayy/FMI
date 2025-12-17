package bg.sofia.uni.fmi.mjt.imagekit.filesystem;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;

public class LocalFileSystemImageManager implements FileSystemImageManager {

    public LocalFileSystemImageManager() {
    }

    private static final Set<String> SUPPORTED_EXTENSIONS = Set.of("jpg", "jpeg", "png", "bmp");

    private void validateFileForLoading(File imageFile) throws IOException {
        if (imageFile == null) {
            throw new IllegalArgumentException("File must not be null");
        }

        if (!imageFile.exists()) {
            throw new IOException("File does not exist: " + imageFile.getPath());
        }

        if (!imageFile.isFile()) {
            throw new IOException("Path is not a regular file: " + imageFile.getPath());
        }

        if (!hasSupportedExtension(imageFile)) {
            throw new IOException("Unsupported file extension: " + imageFile.getName() +
                ". Supported formats: JPEG, PNG, BMP");
        }
    }

    private void validateDirectory(File directory) throws IOException {
        if (directory == null) {
            throw new IllegalArgumentException("Directory must not be null");
        }

        if (!directory.exists()) {
            throw new IOException("Directory does not exist: " + directory.getPath());
        }

        if (!directory.isDirectory()) {
            throw new IOException("Path is not a directory: " + directory.getPath());
        }
    }

    private boolean hasSupportedExtension(File file) {
        String fileName = file.getName().toLowerCase();
        int dotIndex = fileName.lastIndexOf('.');

        if (dotIndex == -1) {
            return false;
        }

        String extension = fileName.substring(dotIndex + 1);
        return SUPPORTED_EXTENSIONS.contains(extension);
    }

    private String getFormatFromExtension(File file) {
        String fileName = file.getName().toLowerCase();

        if (fileName.endsWith(".jpg") || fileName.endsWith(".jpeg")) {
            return "JPEG";
        } else if (fileName.endsWith(".png")) {
            return "PNG";
        } else if (fileName.endsWith(".bmp")) {
            return "BMP";
        } else {
            return "PNG";
        }
    }

    @Override
    public BufferedImage loadImage(File imageFile) throws IOException {
        validateFileForLoading(imageFile);

        try (InputStream is = new FileInputStream(imageFile)) {
            BufferedImage image = ImageIO.read(is);

            if (image == null) {
                throw new IOException("Unsupported image format or corrupted file: " + imageFile.getPath());
            }

            return image;
        }
    }

    @Override
    public List<BufferedImage> loadImagesFromDirectory(File imagesDirectory) throws IOException {
        validateDirectory(imagesDirectory);
        File[] files = imagesDirectory.listFiles();
        if (files == null) {
            return new ArrayList<>();
        }
        List<BufferedImage> images = new ArrayList<>();
        List<String> errorMessages = new ArrayList<>();

        for (File file : files) {
            if (file.isFile() && hasSupportedExtension(file)) {
                try {
                    BufferedImage image = loadImage(file);
                    images.add(image);
                } catch (IOException e) {
                    errorMessages.add(file.getName() + ": " + e.getMessage());
                }
            }
        }

        if (!errorMessages.isEmpty()) {
            throw new IOException("Failed to load some images");
        }

        if (images.isEmpty()) {
            throw new IOException("No supported image files found in directory: " + imagesDirectory.getPath());
        }

        return images;
    }

    @Override
    public void saveImage(BufferedImage image, File imageFile) throws IOException {
        if (image == null) {
            throw new IllegalArgumentException("Image must not be null");
        }

        if (imageFile == null) {
            throw new IllegalArgumentException("File must not be null");
        }

        if (imageFile.exists()) {
            throw new IOException("File already exists: " + imageFile.getPath());
        }

        File parentDir = imageFile.getParentFile();
        if (parentDir != null && !parentDir.exists()) {
            throw new IOException("Parent directory does not exist: " + parentDir.getPath());
        }

        String formatName = getFormatFromExtension(imageFile);
        boolean success = ImageIO.write(image, formatName, imageFile);

        if (!success) {
            throw new IOException("Failed to save image with format: " + formatName);
        }
    }
}
