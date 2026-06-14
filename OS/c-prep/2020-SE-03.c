#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

typedef struct Triple {
    uint8_t fname[8];
    uint32_t offset;
    uint32_t length;
} Triple;

void doChild(Triple, int);
void doChild(Triple t, int toParent){
    int fd = open((char*)t.fname, O_RDONLY);
    if(fd==-1){
        err(1, "open");
    }
    if(lseek(fd, (off_t)t.offset*sizeof(uint16_t), SEEK_SET) == -1){
        err(1, "lseek");
    }

    uint16_t result = 0;
    uint16_t element;
    for(int i = 0; i < t.length ; i++){
        if(read(fd, &element, sizeof(uint16_t)) == -1){
            err(1, "read");
        }
        result ^= element;
    }
    close(fd);

    if(write(toParent, &result, sizeof(uint16_t)) == -1){
        err(1, "write");
    }
}

int main(int argc, char* argv[]){
    if(argc!=2){
        errx(1, "argc");
    }

    int in = open(argv[1], O_RDONLY);
    if(in==-1){
        err(1, "open");
    }

    int pipes[8][2];
    pid_t pids[8];

    int counter = 0;
    ssize_t readSize;
    Triple t;
    while(((readSize = read(in, &t, sizeof(Triple))) > 0) && counter < 8){
        if(pipe(pipes[counter]) == -1){
            err(1, "pipe");
        }

        pid_t pid = fork();
        if(pid==-1){
            err(1, "fork");
        }

        if(pid == 0){
            //child
            close(pipes[counter][0]);

            int toParent = pipes[counter][1];
            doChild(t, toParent);

            close(toParent);
            close(in);
            exit(0);
        }
        //parent
        close(pipes[counter][1]);
        pids[counter] = pid;
        counter++;
    }
    if (readSize == -1){
        err(1, "read");
    }

    uint16_t result = 0;
    for(int i = 0; i< counter; i++){
        waitpid(pids[i]);
        uint16_t val;
        if(read(pipes[i][0], &val, sizeof(uint16_t)) == -1){
            err(1, "read");
        }
        result^=val;
    }

    char buf[32];
    int len = snprintf(buf, sizeof(buf), "result: %04X\n", result);
    if(len==-1){
        err(1, "snprintf");
    }
    write(1, buf, len);

    close(in);
    return 0;
}