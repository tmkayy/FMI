#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    if(argc != 3){
        errx(1, "argc");
    }

    int out = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0666);
    if(out==-1){
        err(1, "open");
    }

    int pfd[2];
    if(pipe(pfd) == -1){
        err(1, "pipe");
    }

    pid_t pid = fork();
    if(pid==-1){
        err(1, "fork");
    }
    if(pid==0){
        close(pfd[0]);
        if(dup2(pfd[1], 1)==-1){
            err(1, "dup2");
        }
        close(pfd[1]);
        execlp("/usr/bin/cat", "cat", argv[1], NULL);
        err(1, "execlp");
    }
    close(pfd[1]);

    ssize_t readSize;
    uint8_t byte;
    int escaped = 0;
    while((readSize = read(pfd[0], &byte, 1)) > 0){
        if(escaped){
            byte^=0x20;
            escaped = 0;
            if(write(out, &byte, 1) == -1){
                err(1, "write");
            }
        } else if (byte == 0x7D){
            escaped = 1;
        } else if (byte == 0x55) {
            continue;
        } else {
            if(write(out, &byte, 1) == -1){
                err(1, "write");
            }
        }
    }

    if(readSize == -1){
        err(1, "read");
    }

    close(pfd[0]);
    close(out);
    return 0;
}