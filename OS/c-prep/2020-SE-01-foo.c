#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

const char* FIFO_PATH = "/tmp/myfifo";

int main(int argc, char* argv[]){
    if(argc!=2){
        errx(1, "argc");
    }

    if(mkfifo(FIFO_PATH, 0666) == -1){
        err(1, "mkfifo");
    }

    int fifo = open(FIFO_PATH, O_WRONLY);
    if(fifo == -1){
        err(1, "open");
    }

    if(dup2(fifo, 1) == -1){
        err(1, "dup2");
    }
    close(fifo);
    execlp("/usr/bin/cat", "cat", argv[1], NULL);
    err(1, "execlp");
}