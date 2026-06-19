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
#include <signal.h>

int main(int argc, char* argv[]){
    if(argc<2 || argc>11){
        errx(1, "argc");
    }

    int numChildren = argc-1;
    pid_t pids[numChildren];

    for(int i = 0; i<numChildren; i++){
        pid_t pid = fork();
        if(pid==-1){
            err(1, "fork");
        }
        if(pid==0){
            //child
            execlp(argv[i+1], argv[i+1], NULL);
            err(1, "execlp");
        }
        pids[i] = pid;
    }

    //parent
    while (done < numChildren) {
        int status;
        pid_t finished = wait(&status);

        for (int i = 0; i < numChildren; i++) {
            if (pids[i] != finished)
                continue;
            if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
                done++;
            } else if (WIFEXITED(status)) {
                pid_t pid = fork();
                if (pid == 0) {
                    execlp(argv[i+1], argv[i+1], NULL); err(1, "execlp");
                }
                pids[i] = pid;
            } else {
                for (int j = 0; j < numChildren; j++) {
                    if (pids[j] == finished)
                        continue;
                    kill(pids[j], SIGTERM);
                    waitpid(pids[j], NULL, 0);
                }
                exit(i + 1);
            }
        }
    }
    return 0;
}