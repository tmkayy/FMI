#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(void){
    int pfd1[2], pfd2[2], pfd3[2], pfd4[2];
    if(pipe(pfd1) == -1){
        err(1, "pipe");
    }
    if(pipe(pfd2) == -1){
        err(1, "pipe");
    }
    if(pipe(pfd3) == -1){
        err(1, "pipe");
    }
    if(pipe(pfd4) == -1){
        err(1, "pipe");
    }

    //cat /etc/passwd
    int p1 = fork();
    if (p1 == -1){
        err(1, "fork");
    }
    if(p1 == 0){
        close(pfd1[0]);
        if(dup2(pfd1[1], 1)==-1){
            err(1, "dup2");
        } close(pfd1[1]);
        close(pfd2[0]); close(pfd2[1]);
        close(pfd3[0]); close(pfd3[1]);
        close(pfd4[0]); close(pfd4[1]);
        execlp("/usr/bin/cat", "cat", "/etc/passwd", NULL);
        err(1, "execlp");
    }

    //cut -d: -f7
    pid_t p2 = fork();
    if (p2 == -1){
        err(1, "fork");
    }
    if(p2 == 0){
        if(dup2(pfd1[0], 0) == -1){
            err(1, "dup2");
        } close(pfd1[0]); close(pfd1[1]);
        if(dup2(pfd2[1], 1) == -1){
            err(1, "dup2");
        } close(pfd2[0]); close(pfd2[1]);
        close(pfd3[0]); close(pfd3[1]);
        close(pfd4[0]); close(pfd4[1]);
        execlp("/usr/bin/cut", "cut", "-d:", "-f7", NULL);
        err(1, "execlp");
    }

    //sort
    pid_t p3 = fork();
    if (p3 == -1) err(1, "fork");
    if (p3 == 0) {
        if(dup2(pfd2[0], 0)==-1){
            err(1, "dup2");
        } close(pfd2[0]); close(pfd2[1]);
        if(dup2(pfd3[1], 1)==-1){
            err(1, "dup2");
        } close(pfd3[0]); close(pfd3[1]);
        close(pfd1[0]); close(pfd1[1]);
        close(pfd4[0]); close(pfd4[1]);
        execlp("/usr/bin/sort", "sort", NULL);
        err(1, "execlp");
    }

    //uniq -c
    pid_t p4 = fork();
    if (p4 == -1) err(1, "fork");
    if (p4 == 0) {
        dup2(pfd3[0], 0); close(pfd3[0]); close(pfd3[1]);
        dup2(pfd4[1], 1); close(pfd4[0]); close(pfd4[1]);
        close(pfd1[0]); close(pfd1[1]);
        close(pfd2[0]); close(pfd2[1]);
        execlp("/usr/bin/uniq", "uniq", "-c", NULL);
        err(1, "execlp");
    }

    // sort -n
    pid_t p5 = fork();
    if (p5 == -1) err(1, "fork");
    if (p5 == 0) {
        dup2(pfd4[0], 0); close(pfd4[0]); close(pfd4[1]);
        close(pfd1[0]); close(pfd1[1]);
        close(pfd2[0]); close(pfd2[1]);
        close(pfd3[0]); close(pfd3[1]);
        execlp("sort", "sort", "-n", NULL);
        err(1, "execlp sort -n");
    }


    close(pfd1[0]); close(pfd1[1]);
    close(pfd2[0]); close(pfd2[1]);
    close(pfd3[0]); close(pfd3[1]);
    close(pfd4[0]); close(pfd4[1]);

    waitpid(p1, NULL, 0);
    waitpid(p2, NULL, 0);
    waitpid(p3, NULL, 0);
    waitpid(p4, NULL, 0);
    waitpid(p5, NULL, 0);

    return 0;
}