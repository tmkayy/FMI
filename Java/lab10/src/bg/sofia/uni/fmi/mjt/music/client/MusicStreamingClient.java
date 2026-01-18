package bg.sofia.uni.fmi.mjt.music.client;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class MusicStreamingClient {
    private static final String SERVER_HOST = "localhost";
    private static final int REQUIRED_ARGS_COUNT = 1;
    private static final int PORT_ARG_INDEX = 0;

    public static void main(String[] args) {
        if (!validateArguments(args)) {
            return;
        }

        int port = Integer.parseInt(args[PORT_ARG_INDEX]);
        runClient(port);
    }

    private static boolean validateArguments(String[] args) {
        if (args.length != REQUIRED_ARGS_COUNT) {
            System.err.println("Usage: java MusicStreamingClient <port>");
            return false;
        }
        return true;
    }

    private static void runClient(int port) {
        try (Socket socket = new Socket(SERVER_HOST, port);
             BufferedReader reader = createReader(socket);
             PrintWriter writer = createWriter(socket);
             Scanner scanner = new Scanner(System.in)) {

            printWelcomeMessage();
            handleUserInput(reader, writer, scanner);

        } catch (IOException e) {
            System.err.println("Error connecting to server: " + e.getMessage());
        }
    }

    private static BufferedReader createReader(Socket socket) throws IOException {
        return new BufferedReader(new InputStreamReader(socket.getInputStream()));
    }

    private static PrintWriter createWriter(Socket socket) throws IOException {
        return new PrintWriter(socket.getOutputStream(), true);
    }

    private static void printWelcomeMessage() {
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
    }

    private static void handleUserInput(BufferedReader reader, PrintWriter writer, Scanner scanner)
        throws IOException {
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
    }
}