package bg.sofia.uni.fmi.mjt.music.server.model;

import java.util.Map;

public class Playlist {
    private final String name;
    private final Map<Song, Integer> songs;

    public Playlist(String name, Map<Song, Integer> songs) {
        this.name = name;
        this.songs = songs;
    }

    public String getName() {
        return name;
    }

    public Map<Song, Integer> getSongs() {
        return songs;
    }
}