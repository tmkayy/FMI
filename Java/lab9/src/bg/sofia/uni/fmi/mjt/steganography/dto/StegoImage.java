package bg.sofia.uni.fmi.mjt.steganography.dto;

import java.awt.image.BufferedImage;

public record StegoImage(BufferedImage image, String fileName) {

}