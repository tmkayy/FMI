package bg.sofia.uni.fmi.mjt.music.server.model;

import java.util.Objects;

public record Song(String title, String artist, int duration) {
    public Song {
        if (title == null || title.isBlank() || artist == null || artist.isBlank()) {
            throw new IllegalArgumentException("Title and artist cannot be null or blank");
        }
        if (duration <= 0) {
            throw new IllegalArgumentException("Duration must be positive");
        }
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Song song = (Song) o;
        return title.equals(song.title) && artist.equals(song.artist);
    }

    @Override
    public int hashCode() {
        return Objects.hash(title, artist);
    }
}