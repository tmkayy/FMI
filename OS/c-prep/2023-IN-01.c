#include <err.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

const char *WORDS[] = {"tic ", "tac ", "toe\n"};

void doWork(int readFromFD, int writeToFD, int wordCount);

void doWork(int readFromFD, int writeToFD, int wordCount) {
    ssize_t readSize;
    int lastIndex;

    while ((readSize = read(readFromFD, &lastIndex, sizeof(lastIndex))) > 0) {
        int toPrint = lastIndex + 1;

        if (toPrint >= wordCount) {
            if (write(writeToFD, &toPrint, sizeof(toPrint)) == -1) {
                err(1, "write");
            }
            return;
        }

        if (write(1, WORDS[toPrint % 3], strlen(WORDS[toPrint % 3])) == -1) {
            err(1, "write");
        }

        if (write(writeToFD, &toPrint, sizeof(toPrint)) == -1) {
            err(1, "write");
        }
    }
    if (readSize == -1) {
        err(1, "read");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        errx(1, "args");
    }

    char *endptr;

    int numChildren = strtol(argv[1], &endptr, 10);
    if (*argv[1] == '\0' || *endptr != '\0') {
        errx(1, "not a number");
    }

    int wordCount = strtol(argv[2], &endptr, 10);
    if (*argv[2] == '\0' || *endptr != '\0') {
        errx(1, "not a number");
    }

    if (numChildren < 1 || numChildren > 7) {
        errx(1, "1 <= numChildren <= 7");
    }

    if (wordCount < 1 || wordCount > 35) {
        errx(1, "1 <= wordCount <= 35");
    }

    int pipes[8][2];
    int numPipes = numChildren + 1;
    for (int i = 0; i < numPipes; i++) {
        if (pipe(pipes[i]) == -1) {
            err(1, "pipe");
        }
    }

    // Process 0 is the parent
    // Make sure we loop from i = 1 so that child 1 will have the correct ID
    for (int i = 1; i <= numChildren; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            err(1, "fork");
        }

        if (pid == 0) {
            // child
            int readFrom = pipes[i - 1][0]; // this will underflow if i = 0
            int writeTo = pipes[i][1];

            for (int j = 0; j < numPipes; j++) {
                if (j != i - 1) {
                    close(pipes[j][0]);
                }
                if (j != i) {
                    close(pipes[j][1]);
                }
            }

            doWork(readFrom, writeTo, wordCount);
            close(readFrom);
            close(writeTo);
            exit(0);
        }
    }

    // parent
    int readFrom = pipes[numPipes - 1][0];
    int writeTo = pipes[0][1];

    for (int i = 0; i < numPipes; i++) {
        if (i != numPipes - 1) {
            close(pipes[i][0]);
        }
        if (i != 0) {
            close(pipes[i][1]);
        }
    }

    int toPrint = 0;
    if (write(1, WORDS[toPrint % 3], strlen(WORDS[toPrint % 3])) == -1) {
        err(1, "write");
    }
    if (write(writeTo, &toPrint, sizeof(toPrint)) == -1) {
        err(1, "write");
    }

    doWork(readFrom, writeTo, wordCount);

    close(readFrom);
    close(writeTo);

    for (int i = 0; i < numChildren; i++) {
        if (wait(NULL) == -1) {
            err(1, "wait");
        }
    }

    return 0;
}