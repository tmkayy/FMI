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

static int in_pipes[3][2];
static int out_pipes[3][2];

void send_and_wait(uint8_t byte) {
    for (int i = 0; i < 3; i++) {
        if (write(in_pipes[i][1], &byte, 1) == -1)
            err(1, "write");
    }
    for (int i = 0; i < 3; i++) {
        uint8_t ack;
        if (read(out_pipes[i][0], &ack, 1) != 1)
            errx(1, "no ack");
        if (ack != 0x01)
            errx(1, "bad ack");
    }
}

int main(int argc, char* argv[]){
    if(argc != 4){
        errx(1, "argc");
    }

    for(int i = 0; i<3;i++){
        if (pipe(in_pipes[i]) == -1){
            err(1, "pipe");
        }
        if (pipe(out_pipes[i]) == -1){
            err(1, "pipe");
        }
    }

    for(int i =0; i<3; i++){
        pid_t pid = fork();
        if(pid==-1){
            err(1, "fork");
        }

        if (pid==0){
            close(in_pipes[i][1]);
            dup2(in_pipes[i][0], 0);
            close(in_pipes[i][0]);

            close(out_pipes[i][0]);
            dup2(out_pipes[i][1], 1);
            close(out_pipes[i][1]);

            for (int j = 0; j < 3; j++) {
                if (j == i)
                    continue;
                close(in_pipes[j][0]);  close(in_pipes[j][1]);
                close(out_pipes[j][0]); close(out_pipes[j][1]);
            }

            execlp(argv[i + 1], argv[i + 1], NULL);
            err(1, "execlp");
        }

        close(in_pipes[i][0]);
        close(out_pipes[i][1]);
    }
    
    uint8_t prev = 0;
    uint8_t byte;
    ssize_t readSize;
    while((readSize = read(0, &byte, 1)) > 0){
        int special = (byte == 0x00 || byte == 0x55 || byte == 0x7D || byte == 0xFF);

        if(!special && byte == prev && prev != 0) {
            send_and_wait(0x55);
        }
        if (special) {
            send_and_wait(0x7D);
            send_and_wait(byte ^ 0x20);
        } else {
            send_and_wait(byte);
        }

        prev = byte;
    }

    for (int i = 0; i < 3; i++) {
        close(in_pipes[i][1]);
        close(out_pipes[i][0]);
    }

    for (int i = 0; i < 3; i++)
        wait(NULL);

    return 0;
}