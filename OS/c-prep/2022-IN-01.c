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

const char *DING = "DING ";
const char *DONG = "DONG \n";

void doParent(int, int, int, int);
void doParent(int fromChild, int toChild, int N, int D) {
    uint8_t buf = 0;

    for (int i = 0; i < N; i++) {
        write(1, DING, strlen(DING));
        write(toChild, &buf, 1);
        read(fromChild, &buf, 1);
        sleep(D);
    }
}

void doChild(int, int, int);
void doChild(int fromParent, int toParent, int N) {
    uint8_t buf = 0;

    for (int i = 0; i < N; i++) {
        read(fromParent, &buf, 1);
        write(1, DONG, strlen(DONG));
        write(toParent, &buf, 1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        errx(1, "args");
    }

    int N = atoi(argv[1]);
    int D = atoi(argv[2]);

    int parentToChild[2];
    if (pipe(parentToChild) == -1) {
        err(1, "pipe");
    }

    int childToParent[2];
    if (pipe(childToParent) == -1) {
        err(1, "pipe");
    }

    int pid = fork();
    if (pid == -1) {
        err(1, "fork");
    }

    if (pid == 0) {
        // child
        close(parentToChild[1]);
        close(childToParent[0]);

        int toParent = childToParent[1];
        int fromParent = parentToChild[0];

        doChild(fromParent, toParent, N);

        close(toParent);
        close(fromParent);

        exit(0);
    }

    // parent
    close(parentToChild[0]);
    close(childToParent[1]);

    int toChild = parentToChild[1];
    int fromChild = childToParent[0];

    doParent(fromChild, toChild, N, D);

    close(fromChild);
    close(toChild);

    int status;
    if (wait(&status) == -1) {
        err(1, "wait");
    }
    if (!WIFEXITED(status)) {
        warnx("child was killed");
    }

    return 0;
}