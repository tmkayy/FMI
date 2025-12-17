import bg.sofia.uni.fmi.mjt.imagekit.filesystem.FileSystemImageManager;
import bg.sofia.uni.fmi.mjt.imagekit.filesystem.LocalFileSystemImageManager;
import bg.sofia.uni.fmi.mjt.imagekit.algorithm.grayscale.LuminosityGrayscale;
import bg.sofia.uni.fmi.mjt.imagekit.algorithm.detection.SobelEdgeDetection;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;


void main() {
    try {
        FileSystemImageManager fsImageManager = new LocalFileSystemImageManager();

        // Load image
        BufferedImage image = fsImageManager.loadImage(new File("kitten.png"));

        // Create algorithms
        LuminosityGrayscale grayscaleAlgorithm = new LuminosityGrayscale();
        SobelEdgeDetection sobelEdgeDetection = new SobelEdgeDetection(grayscaleAlgorithm);

        // Process images
        BufferedImage grayscaleImage = grayscaleAlgorithm.process(image);
        BufferedImage edgeDetectedImage = sobelEdgeDetection.process(image);

        // Save results
        fsImageManager.saveImage(grayscaleImage, new File("kitten_grayscale.png"));
        fsImageManager.saveImage(edgeDetectedImage, new File("kitten_edges.png"));
    } catch (IOException e) {
        System.out.println("Error: " + e.getMessage());
    }
}