package bg.sofia.uni.fmi.mjt.music.server;

import bg.sofia.uni.fmi.mjt.music.server.model.Playlist;
import bg.sofia.uni.fmi.mjt.music.server.model.Song;
import bg.sofia.uni.fmi.mjt.music.server.repository.PlaylistRepository;
import bg.sofia.uni.fmi.mjt.music.server.repository.exception.PlaylistAlreadyExistsException;
import bg.sofia.uni.fmi.mjt.music.server.repository.exception.PlaylistNotFoundException;
import bg.sofia.uni.fmi.mjt.music.server.repository.exception.SongAlreadyExistsException;
import bg.sofia.uni.fmi.mjt.music.server.repository.exception.SongNotFoundException;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Map;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class MusicStreamingServer {
    private static final int MAX_EXECUTOR_THREADS = 10;
    private static final int SHUTDOWN_TIMEOUT_SECONDS = 5;
    private static final int MIN_DURATION = 1;

    private static final int COMMAND_INDEX = 0;
    private static final int PLAYLIST_NAME_INDEX = 1;
    private static final int SONG_TITLE_INDEX = 2;
    private static final int ARTIST_NAME_INDEX = 3;
    private static final int DURATION_INDEX = 4;

    private static final int REQUIRED_PARAMS_CREATE_PLAYLIST = 2;
    private static final int REQUIRED_PARAMS_ADD_SONG = 5;
    private static final int REQUIRED_PARAMS_LIKE_SONG = 4;
    private static final int REQUIRED_PARAMS_UNLIKE_SONG = 4;
    private static final int REQUIRED_PARAMS_GET_PLAYLIST = 2;
    private static final int REQUIRED_PARAMS_LIST_PLAYLISTS = 1;

    private final int port;
    private final PlaylistRepository playlistRepository;
    private ServerSocket serverSocket;
    private final ExecutorService executorService;
    private volatile boolean isRunning;

    public MusicStreamingServer(int port, PlaylistRepository playlistRepository) {
        this.port = port;
        this.playlistRepository = playlistRepository;
        this.executorService = Executors.newFixedThreadPool(MAX_EXECUTOR_THREADS);
        this.isRunning = false;
    }

    public void start() {
        try {
            serverSocket = new ServerSocket(port);
            isRunning = true;
            System.out.println("Server started on port " + port);

            while (isRunning) {
                try {
                    Socket clientSocket = serverSocket.accept();
                    executorService.submit(new ClientHandler(clientSocket));
                } catch (IOException e) {
                    if (isRunning) {
                        System.err.println("Error accepting client connection: " + e.getMessage());
                    }
                }
            }
        } catch (IOException e) {
            System.err.println("Error starting server: " + e.getMessage());
        }
    }

    public void stop() {
        isRunning = false;
        try {
            if (serverSocket != null && !serverSocket.isClosed()) {
                serverSocket.close();
            }
        } catch (IOException e) {
            System.err.println("Error closing server socket: " + e.getMessage());
        }

        executorService.shutdown();
        try {
            if (!executorService.awaitTermination(SHUTDOWN_TIMEOUT_SECONDS, TimeUnit.SECONDS)) {
                executorService.shutdownNow();
            }
        } catch (InterruptedException e) {
            executorService.shutdownNow();
            Thread.currentThread().interrupt();
        }
        System.out.println("Server stopped");
    }

    private class ClientHandler implements Runnable {
        private final Socket clientSocket;

        public ClientHandler(Socket socket) {
            this.clientSocket = socket;
        }

        @Override
        public void run() {
            try (BufferedReader reader = new BufferedReader(
                new InputStreamReader(clientSocket.getInputStream()));
                 PrintWriter writer = new PrintWriter(clientSocket.getOutputStream(), true)) {

                String clientMessage;
                while ((clientMessage = reader.readLine()) != null) {
                    String response = processCommand(clientMessage);
                    writer.println(response);

                    if (clientMessage.trim().equals("disconnect")) {
                        break;
                    }
                }
            } catch (IOException e) {
                System.err.println("Error handling client: " + e.getMessage());
            } finally {
                try {
                    clientSocket.close();
                } catch (IOException e) {
                    System.err.println("Error closing client socket: " + e.getMessage());
                }
            }
        }

        private String processCommand(String commandLine) {
            String[] parts = commandLine.trim().split("\\s+");
            if (parts.length == 0) {
                return createErrorResponse("Empty command");
            }

            String command = parts[COMMAND_INDEX];

            return switch (command) {
                case "create-playlist" -> handleCreatePlaylist(parts);
                case "add-song" -> handleAddSong(parts);
                case "like-song" -> handleLikeSong(parts);
                case "unlike-song" -> handleUnlikeSong(parts);
                case "list-playlists" -> handleListPlaylists(parts);
                case "get-playlist" -> handleGetPlaylist(parts);
                case "disconnect" -> handleDisconnect();
                default -> createErrorResponse("Unknown command");
            };
        }

        private String handleCreatePlaylist(String[] parts) {
            if (parts.length != REQUIRED_PARAMS_CREATE_PLAYLIST) {
                return createErrorResponse("Usage: create-playlist <playlist_name>");
            }

            String playlistName = parts[PLAYLIST_NAME_INDEX];
            try {
                playlistRepository.createPlaylist(playlistName);
                return "{\"status\":\"OK\",\"message\":\"Playlist "
                    + escapeJson(playlistName) + " created successfully.\"}";
            } catch (PlaylistAlreadyExistsException e) {
                return createErrorResponse("Playlist " + playlistName + " already exists.");
            }
        }

        private String handleAddSong(String[] parts) {
            if (parts.length != REQUIRED_PARAMS_ADD_SONG) {
                return createErrorResponse("Usage: add-song <playlist_name> <song_title> <artist_name> <duration>");
            }

            String playlistName = parts[PLAYLIST_NAME_INDEX];
            String songTitle = parts[SONG_TITLE_INDEX];
            String artistName = parts[ARTIST_NAME_INDEX];
            int duration;

            try {
                duration = Integer.parseInt(parts[DURATION_INDEX]);
                if (duration < MIN_DURATION) {
                    return createErrorResponse("Duration must be a positive integer");
                }
            } catch (NumberFormatException e) {
                return createErrorResponse("Duration must be a positive integer");
            }

            try {
                playlistRepository.addSong(playlistName, songTitle, artistName, duration);
                return "{\"status\":\"OK\",\"message\":\"Song " + escapeJson(songTitle)
                    + " by " + escapeJson(artistName) + " added successfully.\"}";
            } catch (PlaylistNotFoundException e) {
                return createErrorResponse("Playlist " + playlistName + " does not exist.");
            } catch (SongAlreadyExistsException e) {
                return createErrorResponse("Song " + songTitle + " by "
                    + artistName + " already exists in playlist " + playlistName + ".");
            }
        }

        private String handleLikeSong(String[] parts) {
            if (parts.length != REQUIRED_PARAMS_LIKE_SONG) {
                return createErrorResponse("Usage: like-song <playlist_name> <song_title> <artist_name>");
            }

            String playlistName = parts[PLAYLIST_NAME_INDEX];
            String songTitle = parts[SONG_TITLE_INDEX];
            String artistName = parts[ARTIST_NAME_INDEX];

            try {
                int likes = playlistRepository.likeSong(playlistName, songTitle, artistName);
                return "{\"status\":\"OK\",\"message\":\"Song " + escapeJson(songTitle)
                    + " by " + escapeJson(artistName) + " liked. Likes: " + likes + "\"}";
            } catch (PlaylistNotFoundException e) {
                return createErrorResponse("Playlist " + playlistName + " does not exist.");
            } catch (SongNotFoundException e) {
                return createErrorResponse("Song " + songTitle + " by "
                    + artistName + " does not exist in playlist " + playlistName + ".");
            }
        }

        private String handleUnlikeSong(String[] parts) {
            if (parts.length != REQUIRED_PARAMS_UNLIKE_SONG) {
                return createErrorResponse("Usage: unlike-song <playlist_name> <song_title> <artist_name>");
            }

            String playlistName = parts[PLAYLIST_NAME_INDEX];
            String songTitle = parts[SONG_TITLE_INDEX];
            String artistName = parts[ARTIST_NAME_INDEX];

            try {
                int likes = playlistRepository.unlikeSong(playlistName, songTitle, artistName);
                return "{\"status\":\"OK\",\"message\":\"Song " + escapeJson(songTitle)
                    + " by " + escapeJson(artistName) + " unliked. Likes: " + likes + "\"}";
            } catch (PlaylistNotFoundException e) {
                return createErrorResponse("Playlist " + playlistName + " does not exist.");
            } catch (SongNotFoundException e) {
                return createErrorResponse("Song " + songTitle + " by "
                    + artistName + " does not exist in playlist " + playlistName + ".");
            }
        }

        private String handleListPlaylists(String[] parts) {
            if (parts.length != REQUIRED_PARAMS_LIST_PLAYLISTS) {
                return createErrorResponse("Usage: list-playlists");
            }

            var playlists = playlistRepository.getAllPlaylists();
            StringBuilder response = new StringBuilder("{\"status\":\"OK\",\"playlists\":[");

            boolean first = true;
            for (String playlist : playlists) {
                if (!first) {
                    response.append(",");
                }
                response.append("\"").append(escapeJson(playlist)).append("\"");
                first = false;
            }
            response.append("]}");

            return response.toString();
        }

        private String handleGetPlaylist(String[] parts) {
            if (parts.length != REQUIRED_PARAMS_GET_PLAYLIST) {
                return createErrorResponse("Usage: get-playlist <playlist_name>");
            }
            String playlistName = parts[PLAYLIST_NAME_INDEX];

            try {
                Playlist playlist = playlistRepository.getPlaylist(playlistName);
                StringBuilder response = new StringBuilder("{\"status\":\"OK\",\"playlist\":{\"name\":\"");
                response.append(escapeJson(playlist.getName())).append("\",\"songs\":[");
                boolean firstSong = true;
                for (Map.Entry<Song, Integer> entry : playlist.getSongs().entrySet()) {
                    Song song = entry.getKey();
                    int likes = entry.getValue();
                    if (!firstSong) {
                        response.append(",");
                    }

                    response.append("{\"title\":\"").append(escapeJson(song.title()))
                        .append("\",\"artist\":\"").append(escapeJson(song.artist()))
                        .append("\",\"duration\":").append(song.duration())
                        .append(",\"likes\":").append(likes).append("}");
                    firstSong = false;
                }
                response.append("]}}");
                return response.toString();
            } catch (PlaylistNotFoundException e) {
                return createErrorResponse("Playlist " + playlistName + " does not exist.");
            }
        }

        private String handleDisconnect() {
            return "{\"status\":\"OK\",\"message\":\"Disconnected successfully\"}";
        }

        private String createErrorResponse(String message) {
            return "{\"status\":\"ERROR\",\"message\":\"" + escapeJson(message) + "\"}";
        }

        private String escapeJson(String input) {
            if (input == null) {
                return "";
            }

            StringBuilder escaped = new StringBuilder();
            for (char c : input.toCharArray()) {
                switch (c) {
                    case '"' -> escaped.append("\\\"");
                    case '\\' -> escaped.append("\\\\");
                    case '\b' -> escaped.append("\\b");
                    case '\f' -> escaped.append("\\f");
                    case '\n' -> escaped.append("\\n");
                    case '\r' -> escaped.append("\\r");
                    case '\t' -> escaped.append("\\t");
                    default -> escaped.append(c);
                }
            }
            return escaped.toString();
        }
    }
}