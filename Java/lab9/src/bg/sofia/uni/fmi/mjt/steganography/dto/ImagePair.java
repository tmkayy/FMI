package bg.sofia.uni.fmi.mjt.steganography.dto;

import java.awt.image.BufferedImage;

public record ImagePair(BufferedImage coverImage, BufferedImage secretImage, String fileName) {

}