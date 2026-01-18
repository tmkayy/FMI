package bg.sofia.uni.fmi.mjt.music.client;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class MusicStreamingClient {
    private static final String SERVER_HOST = "localhost";

    public static void main(String[] args) {
        if (args.length != 1) {
            System.err.println("Usage: java MusicStreamingClient <port>");
            return;
        }

        int port = Integer.parseInt(args[0]);

        try (Socket socket = new Socket(SERVER_HOST, port);
             BufferedReader reader = new BufferedReader(
                 new InputStreamReader(socket.getInputStream()));
             PrintWriter writer = new PrintWriter(socket.getOutputStream(), true);
             Scanner scanner = new Scanner(System.in)) {

            System.out.println("Connected to Music Streaming Server");
            System.out.println("Available commands:");
            System.out.println("  create-playlist <name>");
            System.out.println("  add-song <playlist> <title> <artist> <duration>");
            System.out.println("  like-song <playlist> <title> <artist>");
            System.out.println("  unlike-song <playlist> <title> <artist>");
            System.out.println("  list-playlists");
            System.out.println("  get-playlist <name>");
            System.out.println("  disconnect");
            System.out.println();

            while (true) {
                System.out.print("> ");
                String command = scanner.nextLine();

                writer.println(command);

                String response = reader.readLine();
                System.out.println(response);

                if (command.trim().equals("disconnect")) {
                    break;
                }
            }

        } catch (IOException e) {
            System.err.println("Error connecting to server: " + e.getMessage());
        }
    }
}