package bg.sofia.uni.fmi.mjt.music;

import bg.sofia.uni.fmi.mjt.music.server.MusicStreamingServer;
import bg.sofia.uni.fmi.mjt.music.server.repository.InMemoryPlaylistRepository;

public class ServerMain {
    private static final int DEFAULT_PORT = 8080;

    public static void main(String[] args) {
        int port = args.length > 0 ? Integer.parseInt(args[0]) : DEFAULT_PORT;

        InMemoryPlaylistRepository repository = new InMemoryPlaylistRepository();
        MusicStreamingServer server = new MusicStreamingServer(port, repository);

        Runtime.getRuntime().addShutdownHook(new Thread(() -> {
            System.out.println("\nShutting down server...");
            server.stop();
        }));

        server.start();
    }
}