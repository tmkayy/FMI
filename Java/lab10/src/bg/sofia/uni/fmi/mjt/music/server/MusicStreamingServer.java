package bg.sofia.uni.fmi.mjt.music.server;

import bg.sofia.uni.fmi.mjt.music.server.model.Playlist;
import bg.sofia.uni.fmi.mjt.music.server.model.Song;
import bg.sofia.uni.fmi.mjt.music.server.repository.PlaylistRepository;
import com.google.gson.Gson;
import com.google.gson.JsonArray;
import com.google.gson.JsonObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class MusicStreamingServer {
    private static final int MAX_EXECUTOR_THREADS = 10;
    private static final Gson GSON = new Gson();

    private final int port;
    private final PlaylistRepository playlistRepository;
    private ServerSocket serverSocket;
    private ExecutorService executorService;
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
                Socket clientSocket = serverSocket.accept();
                executorService.submit(new ClientHandler(clientSocket));
            }
        } catch (IOException e) {
            if (isRunning) {
                System.err.println("Error accepting client connection: " + e.getMessage());
            }
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
            if (!executorService.awaitTermination(5, TimeUnit.SECONDS)) {
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

            String command = parts[0];

            try {
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
            } catch (Exception e) {
                return createErrorResponse(e.getMessage());
            }
        }

        private String handleCreatePlaylist(String[] parts) {
            if (parts.length != 2) {
                return createErrorResponse("Usage: create-playlist <playlist_name>");
            }

            String playlistName = parts[1];
            try {
                playlistRepository.createPlaylist(playlistName);
                JsonObject response = new JsonObject();
                response.addProperty("status", "OK");
                response.addProperty("message", "Playlist " + playlistName + " created successfully.");
                return GSON.toJson(response);
            } catch (PlaylistAlreadyExistsException e) {
                return createErrorResponse("Playlist " + playlistName + " already exists.");
            }
        }

        private String handleAddSong(String[] parts) {
            if (parts.length != 5) {
                return createErrorResponse("Usage: add-song <playlist_name> <song_title> <artist_name> <duration>");
            }

            String playlistName = parts[1];
            String songTitle = parts[2];
            String artistName = parts[3];
            int duration;

            try {
                duration = Integer.parseInt(parts[4]);
                if (duration <= 0) {
                    return createErrorResponse("Duration must be a positive integer");
                }
            } catch (NumberFormatException e) {
                return createErrorResponse("Duration must be a positive integer");
            }

            try {
                playlistRepository.addSong(playlistName, songTitle, artistName, duration);
                JsonObject response = new JsonObject();
                response.addProperty("status", "OK");
                response.addProperty("message",
                    "Song " + songTitle + " by " + artistName + " added successfully.");
                return GSON.toJson(response);
            } catch (PlaylistNotFoundException e) {
                return createErrorResponse("Playlist " + playlistName + " does not exist.");
            } catch (SongAlreadyExistsException e) {
                return createErrorResponse(
                    "Song " + songTitle + " by " + artistName + " already exists in playlist " + playlistName + "."
                );
            }
        }

        private String handleLikeSong(String[] parts) {
            if (parts.length != 4) {
                return createErrorResponse("Usage: like-song <playlist_name> <song_title> <artist_name>");
            }

            String playlistName = parts[1];
            String songTitle = parts[2];
            String artistName = parts[3];

            try {
                int likes = playlistRepository.likeSong(playlistName, songTitle, artistName);
                JsonObject response = new JsonObject();
                response.addProperty("status", "OK");
                response.addProperty("message",
                    "Song " + songTitle + " by " + artistName + " liked. Likes: " + likes);
                return GSON.toJson(response);
            } catch (PlaylistNotFoundException e) {
                return createErrorResponse("Playlist " + playlistName + " does not exist.");
            } catch (SongNotFoundException e) {
                return createErrorResponse(
                    "Song " + songTitle + " by " + artistName + " does not exist in playlist " + playlistName + "."
                );
            }
        }

        private String handleUnlikeSong(String[] parts) {
            if (parts.length != 4) {
                return createErrorResponse("Usage: unlike-song <playlist_name> <song_title> <artist_name>");
            }

            String playlistName = parts[1];
            String songTitle = parts[2];
            String artistName = parts[3];

            try {
                int likes = playlistRepository.unlikeSong(playlistName, songTitle, artistName);
                JsonObject response = new JsonObject();
                response.addProperty("status", "OK");
                response.addProperty("message",
                    "Song " + songTitle + " by " + artistName + " unliked. Likes: " + likes);
                return GSON.toJson(response);
            } catch (PlaylistNotFoundException e) {
                return createErrorResponse("Playlist " + playlistName + " does not exist.");
            } catch (SongNotFoundException e) {
                return createErrorResponse(
                    "Song " + songTitle + " by " + artistName + " does not exist in playlist " + playlistName + "."
                );
            }
        }

        private String handleListPlaylists(String[] parts) {
            if (parts.length != 1) {
                return createErrorResponse("Usage: list-playlists");
            }

            var playlists = playlistRepository.getAllPlaylists();
            JsonObject response = new JsonObject();
            response.addProperty("status", "OK");
            JsonArray playlistArray = new JsonArray();
            playlists.forEach(playlistArray::add);
            response.add("playlists", playlistArray);
            return GSON.toJson(response);
        }

        private String handleGetPlaylist(String[] parts) {
            if (parts.length != 2) {
                return createErrorResponse("Usage: get-playlist <playlist_name>");
            }

            String playlistName = parts[1];

            try {
                Playlist playlist = playlistRepository.getPlaylist(playlistName);

                JsonObject response = new JsonObject();
                response.addProperty("status", "OK");

                JsonObject playlistJson = new JsonObject();
                playlistJson.addProperty("name", playlist.getName());

                JsonArray songsArray = new JsonArray();
                for (Map.Entry<Song, Integer> entry : playlist.getSongs().entrySet()) {
                    Song song = entry.getKey();
                    int likes = entry.getValue();

                    JsonObject songJson = new JsonObject();
                    songJson.addProperty("title", song.title());
                    songJson.addProperty("artist", song.artist());
                    songJson.addProperty("duration", song.duration());
                    songJson.addProperty("likes", likes);

                    songsArray.add(songJson);
                }

                playlistJson.add("songs", songsArray);
                response.add("playlist", playlistJson);

                return GSON.toJson(response);
            } catch (PlaylistNotFoundException e) {
                return createErrorResponse("Playlist " + playlistName + " does not exist.");
            }
        }

        private String handleDisconnect() {
            JsonObject response = new JsonObject();
            response.addProperty("status", "OK");
            response.addProperty("message", "Disconnected successfully");
            return GSON.toJson(response);
        }

        private String createErrorResponse(String message) {
            JsonObject response = new JsonObject();
            response.addProperty("status", "ERROR");
            response.addProperty("message", message);
            return GSON.toJson(response);
        }
    }
}