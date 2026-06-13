#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    if(argc != 2){
        errx(1, "argc");
    }

    int pfd[2];
    if(pipe(pfd) == -1){
        err(1, "pipe");
    }

    int cat_pid = fork();
    if (cat_pid == -1){
        err(1, "fork");
    }

    if (cat_pid == 0){
        //child - cat
        close(pfd[0]);
        if (dup2(pfd[1], 1) == -1){
            err(1, "dup2");
        }
        close(pfd[1]);
        execlp("/usr/bin/cat", "cat", argv[1], (char*) NULL);
        err(1, "execlp");
    }

    int sort_pid = fork();
    if(sort_pid == -1){
        err(1, "fork");
    }

    if(sort_pid == 0){
        //child - sort
        close(pfd[1]);
        if (dup2(pfd[0], 0) == -1){
            err(1, "dup2");
        }
        close(pfd[0]);
        execlp("/usr/bin/sort", "sort", (char*) NULL);
        err(1, "execlp");
    }

    close(pfd[0]);
    close(pfd[1]);

    waitpid(cat_pid, NULL, 0);
    waitpid(sort_pid, NULL, 0);

    return 0;
}