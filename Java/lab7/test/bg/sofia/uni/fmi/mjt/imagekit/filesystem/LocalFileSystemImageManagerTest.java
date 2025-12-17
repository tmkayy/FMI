package bg.sofia.uni.fmi.mjt.imagekit.filesystem;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.io.TempDir;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.ValueSource;

import javax.imageio.ImageIO;
import java.awt.Color;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.Files;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class LocalFileSystemImageManagerTest {

    @TempDir
    File tempDir;

    @Test
    void testLoadImageNullThrowsException() {
        LocalFileSystemImageManager manager = new LocalFileSystemImageManager();
        assertThrows(IllegalArgumentException.class, () -> manager.loadImage(null));
    }

    @Test
    void testLoadImageNonExistentThrowsIOException() {
        LocalFileSystemImageManager manager = new LocalFileSystemImageManager();
        assertThrows(IOException.class, () -> manager.loadImage(new File("nonexistent.jpg")));
    }

    @Test
    void testSaveImageNullImageThrowsException() {
        LocalFileSystemImageManager manager = new LocalFileSystemImageManager();
        File output = new File(tempDir, "test.jpg");
        assertThrows(IllegalArgumentException.class, () -> manager.saveImage(null, output));
    }

    @Test
    void testSaveImageNullFileThrowsException() {
        LocalFileSystemImageManager manager = new LocalFileSystemImageManager();
        BufferedImage image = new BufferedImage(10, 10, BufferedImage.TYPE_INT_RGB);
        assertThrows(IllegalArgumentException.class, () -> manager.saveImage(image, null));
    }

    @Test
    void testSaveAndLoadRoundTrip() throws IOException {
        LocalFileSystemImageManager manager = new LocalFileSystemImageManager();

        BufferedImage original = createTestImage(20, 20);
        File output = new File(tempDir, "test.png");

        manager.saveImage(original, output);
        BufferedImage loaded = manager.loadImage(output);

        assertEquals(original.getWidth(), loaded.getWidth());
        assertEquals(original.getHeight(), loaded.getHeight());
    }

    @ParameterizedTest
    @ValueSource(strings = {"png", "jpg", "bmp"})
    void testSaveDifferentFormats(String format) throws IOException {
        LocalFileSystemImageManager manager = new LocalFileSystemImageManager();
        BufferedImage image = createTestImage(15, 15);
        File output = new File(tempDir, "test." + format);

        manager.saveImage(image, output);
        assertTrue(output.exists());
        assertTrue(output.length() > 0);
    }

    @Test
    void testLoadImagesFromDirectory() throws IOException {
        LocalFileSystemImageManager manager = new LocalFileSystemImageManager();

        File dir = new File(tempDir, "images");
        assertTrue(dir.mkdir());

        ImageIO.write(createTestImage(10, 10), "PNG", new File(dir, "img1.png"));
        ImageIO.write(createTestImage(10, 10), "JPEG", new File(dir, "img2.jpg"));

        List<BufferedImage> images = manager.loadImagesFromDirectory(dir);
        assertEquals(2, images.size());
    }

    @Test
    void testLoadImagesFromDirectoryEmptyThrowsException() throws IOException {
        LocalFileSystemImageManager manager = new LocalFileSystemImageManager();

        File dir = new File(tempDir, "empty");
        assertTrue(dir.mkdir());

        assertThrows(IOException.class, () -> manager.loadImagesFromDirectory(dir));
    }

    @Test
    void testLoadImagesFromDirectoryWithCorruptedFileThrowsException() throws IOException {
        LocalFileSystemImageManager manager = new LocalFileSystemImageManager();

        File dir = new File(tempDir, "mixed");
        assertTrue(dir.mkdir());

        ImageIO.write(createTestImage(10, 10), "PNG", new File(dir, "good.png"));

        File corrupted = new File(dir, "bad.jpg");
        try (FileOutputStream fos = new FileOutputStream(corrupted)) {
            fos.write("Not an image".getBytes());
        }

        assertThrows(IOException.class, () -> manager.loadImagesFromDirectory(dir));
    }

    @Test
    void testSaveImageFileExistsThrowsException() throws IOException {
        LocalFileSystemImageManager manager = new LocalFileSystemImageManager();
        BufferedImage image = createTestImage(10, 10);
        File output = new File(tempDir, "existing.png");

        ImageIO.write(image, "PNG", output);

        assertThrows(IOException.class, () -> manager.saveImage(image, output));
    }

    private BufferedImage createTestImage(int width, int height) {
        BufferedImage image = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                image.setRGB(x, y, Color.RED.getRGB());
            }
        }
        return image;
    }
}