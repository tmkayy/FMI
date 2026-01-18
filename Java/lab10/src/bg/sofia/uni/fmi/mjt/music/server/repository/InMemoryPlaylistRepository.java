package bg.sofia.uni.fmi.mjt.music.server.repository;

import bg.sofia.uni.fmi.mjt.music.server.model.Playlist;
import bg.sofia.uni.fmi.mjt.music.server.model.Song;
import bg.sofia.uni.fmi.mjt.music.server.repository.exception.PlaylistAlreadyExistsException;
import bg.sofia.uni.fmi.mjt.music.server.repository.exception.PlaylistNotFoundException;
import bg.sofia.uni.fmi.mjt.music.server.repository.exception.SongAlreadyExistsException;
import bg.sofia.uni.fmi.mjt.music.server.repository.exception.SongNotFoundException;

import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class InMemoryPlaylistRepository implements PlaylistRepository {
    private final Map<String, Map<Song, Integer>> playlists;

    public InMemoryPlaylistRepository() {
        this.playlists = new ConcurrentHashMap<>();
    }

    @Override
    public void createPlaylist(String playlistName) throws PlaylistAlreadyExistsException {
        if (playlists.containsKey(playlistName)) {
            throw new PlaylistAlreadyExistsException("Playlist " + playlistName + " already exists");
        }
        playlists.put(playlistName, new ConcurrentHashMap<>());
    }

    @Override
    public Song addSong(String playlistName, String songTitle, String artistName, int duration)
        throws PlaylistNotFoundException, SongAlreadyExistsException {

        Map<Song, Integer> playlist = playlists.get(playlistName);
        if (playlist == null) {
            throw new PlaylistNotFoundException("Playlist " + playlistName + " does not exist");
        }

        Song song = new Song(songTitle, artistName, duration);
        if (playlist.containsKey(song)) {
            throw new SongAlreadyExistsException(
                "Song " + songTitle + " by " + artistName + " already exists in playlist " + playlistName
            );
        }

        playlist.put(song, 0);
        return song;
    }

    @Override
    public int likeSong(String playlistName, String songTitle, String artistName)
        throws PlaylistNotFoundException, SongNotFoundException {

        Map<Song, Integer> playlist = playlists.get(playlistName);
        if (playlist == null) {
            throw new PlaylistNotFoundException("Playlist " + playlistName + " does not exist");
        }

        Song songToFind = new Song(songTitle, artistName, 1); // Duration is irrelevant for searching
        Integer likes = playlist.get(songToFind);
        if (likes == null) {
            throw new SongNotFoundException(
                "Song " + songTitle + " by " + artistName + " does not exist in playlist " + playlistName
            );
        }

        int newLikes = likes + 1;
        playlist.put(songToFind, newLikes);
        return newLikes;
    }

    @Override
    public int unlikeSong(String playlistName, String songTitle, String artistName)
        throws PlaylistNotFoundException, SongNotFoundException {

        Map<Song, Integer> playlist = playlists.get(playlistName);
        if (playlist == null) {
            throw new PlaylistNotFoundException("Playlist " + playlistName + " does not exist");
        }

        Song songToFind = new Song(songTitle, artistName, 1);
        Integer likes = playlist.get(songToFind);
        if (likes == null) {
            throw new SongNotFoundException(
                "Song " + songTitle + " by " + artistName + " does not exist in playlist " + playlistName
            );
        }

        int newLikes = Math.max(0, likes - 1);
        playlist.put(songToFind, newLikes);
        return newLikes;
    }

    @Override
    public Collection<String> getAllPlaylists() {
        return new ArrayList<>(playlists.keySet());
    }

    @Override
    public Playlist getPlaylist(String playlistName) throws PlaylistNotFoundException {
        Map<Song, Integer> songs = playlists.get(playlistName);
        if (songs == null) {
            throw new PlaylistNotFoundException("Playlist " + playlistName + " does not exist");
        }
        return new Playlist(playlistName, new HashMap<>(songs));
    }
}