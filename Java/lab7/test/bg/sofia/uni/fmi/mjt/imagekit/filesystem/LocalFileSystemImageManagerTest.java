package bg.sofia.uni.fmi.mjt.imagekit.filesystem;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.io.TempDir;
import javax.imageio.ImageIO;
import java.awt.Color;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNotNull;
import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.junit.jupiter.api.Assertions.assertTrue;

class LocalFileSystemImageManagerTest {

    @TempDir
    File tempDir;

    @Test
    void testLoadImageNullFileThrowsException() {
        LocalFileSystemImageManager manager = new LocalFileSystemImageManager();
        assertThrows(IllegalArgumentException.class, () -> manager.loadImage(null));
    }

    @Test
    void testSaveImageNullImageThrowsException() {
        LocalFileSystemImageManager manager = new LocalFileSystemImageManager();
        File output = new File(tempDir, "test.jpg");
        assertThrows(IllegalArgumentException.class, () -> manager.saveImage(null, output));
    }

    @Test
    void testSaveAndLoadRoundTrip() throws IOException {
        LocalFileSystemImageManager manager = new LocalFileSystemImageManager();

        BufferedImage original = new BufferedImage(10, 10, BufferedImage.TYPE_INT_RGB);
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                original.setRGB(x, y, Color.RED.getRGB());
            }
        }

        File output = new File(tempDir, "test.png");
        manager.saveImage(original, output);

        BufferedImage loaded = manager.loadImage(output);

        assertNotNull(loaded);
        assertEquals(10, loaded.getWidth());
        assertEquals(10, loaded.getHeight());
    }

    @Test
    void testLoadImagesFromDirectory() throws IOException {
        LocalFileSystemImageManager manager = new LocalFileSystemImageManager();

        File dir = new File(tempDir, "images");
        assertTrue(dir.mkdir());

        BufferedImage image1 = new BufferedImage(10, 10, BufferedImage.TYPE_INT_RGB);
        BufferedImage image2 = new BufferedImage(10, 10, BufferedImage.TYPE_INT_RGB);

        ImageIO.write(image1, "PNG", new File(dir, "img1.png"));
        ImageIO.write(image2, "PNG", new File(dir, "img2.png"));

        var images = manager.loadImagesFromDirectory(dir);

        assertEquals(2, images.size());
    }
}