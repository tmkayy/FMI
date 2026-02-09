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

        return modifySongLikes(playlistName, songTitle, artistName, true);
    }

    @Override
    public int unlikeSong(String playlistName, String songTitle, String artistName)
        throws PlaylistNotFoundException, SongNotFoundException {

        return modifySongLikes(playlistName, songTitle, artistName, false);
    }

    private int modifySongLikes(String playlistName, String songTitle, String artistName, boolean increment)
        throws PlaylistNotFoundException, SongNotFoundException {

        Map<Song, Integer> playlist = playlists.get(playlistName);
        if (playlist == null) {
            throw new PlaylistNotFoundException("Playlist " + playlistName + " does not exist");
        }

        Song songToFind = findSongInPlaylist(playlist, songTitle, artistName);
        if (songToFind == null) {
            throw new SongNotFoundException(
                "Song " + songTitle + " by " + artistName + " does not exist in playlist " + playlistName
            );
        }

        Integer currentLikes = playlist.get(songToFind);
        int newLikes = increment ? currentLikes + 1 : Math.max(0, currentLikes - 1);
        playlist.put(songToFind, newLikes);
        return newLikes;
    }

    private Song findSongInPlaylist(Map<Song, Integer> playlist, String songTitle, String artistName) {
        for (Song song : playlist.keySet()) {
            if (song.title().equals(songTitle) && song.artist().equals(artistName)) {
                return song;
            }
        }
        return null;
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