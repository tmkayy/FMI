import bg.sofia.uni.fmi.mjt.steganography.ImageCodec;
import bg.sofia.uni.fmi.mjt.steganography.ImageCodecImpl;

void main() {
    String sourceDirectory = "input";
    String outputDirectory = "output";
    ImageCodec codec = new ImageCodecImpl();
    codec.extractPNGImages(sourceDirectory, outputDirectory);
}