package bg.sofia.uni.fmi.mjt.steganography.io;

import java.io.IOException;
import java.io.UncheckedIOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Comparator;
import java.util.stream.Stream;

public class DirectoryManager {
    private static final String PNG_EXTENSION = ".png";

    public static void createDirectoryIfNotExists(String directory) {
        Path dirPath = Paths.get(directory);
        if (!Files.exists(dirPath)) {
            try {
                Files.createDirectories(dirPath);
            } catch (IOException e) {
                throw new UncheckedIOException("Failed to create directory: " + directory, e);
            }
        }
    }

    public static String[] getSortedPNGFiles(Path directory) throws IOException {
        try (Stream<Path> files = Files.list(directory)) {
            return files.filter(path -> path.toString().toLowerCase().endsWith(PNG_EXTENSION))
                .map(path -> path.getFileName().toString())
                .sorted(Comparator.naturalOrder())
                .toArray(String[]::new);
        }
    }
}