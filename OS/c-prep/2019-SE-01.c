#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[]){
     if(argc< 3){
        errx(1, "argc");
     }

     int threshold = atoi(argv[1]);
     int log = open("run.log", O_WRONLY | O_APPEND | O_CREAT, 0666);
     if(log == -1){
        err(1, "open");
     }
     
     int prev_failed = 0;
     while(1){
        time_t start = time(NULL);
        int pid = fork();
        if(pid==-1){
            err(1, "fork");
        }

        if(pid==0){
            execvp(argv[2], &argv[2]);
            err(1, "execvp");
        }

        int status;
        if(wait(&status) == -1){
            err(1, "wait");
        }

        time_t end = time(NULL);
        int exitcode;
        if(WIFEXITED(status)){
            exitcode = WEXITSTATUS(status);
        } else {
            exitcode = 129;
        }

        char buf[4096];
        int len = snprintf(buf, sizeof(buf), "%ld %ld %d\n", (long)start, (long)end, exitcode);
        if(write(log, buf, len) == -1){
            err(1, "write");
        }
        
        int failed = (exitcode!=0) && ((end - start)<threshold);

        if (failed && prev_failed){
            break;
        }

        prev_failed = failed;
     }
     close(log);
     return 0;
}