package bg.sofia.uni.fmi.mjt.steganography.threading;

import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.function.Function;
import java.util.stream.Collectors;

public class TaskManager implements AutoCloseable {
    private final ExecutorService executorService;

    public TaskManager() {
        int availableProcessors = Runtime.getRuntime().availableProcessors();
        this.executorService = Executors.newFixedThreadPool(availableProcessors);
    }

    public <T, R> List<R> processInParallel(
        List<T> items,
        Function<T, R> processor
    ) throws InterruptedException, ExecutionException {

        List<Callable<R>> tasks = items.stream()
            .map(item -> (Callable<R>) () -> processor.apply(item))
            .collect(Collectors.toList());

        List<Future<R>> futures = executorService.invokeAll(tasks);

        return futures.stream()
            .map(future -> {
                try {
                    return future.get();
                } catch (Exception e) {
                    throw new RuntimeException("Failed to process task", e);
                }
            })
            .collect(Collectors.toList());
    }

    @Override
    public void close() {
        executorService.shutdown();
    }
}