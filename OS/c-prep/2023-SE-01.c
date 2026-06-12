#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    if(argc != 3){
        errx(1, "argc");
    }

    int in = open(argv[1], O_RDONLY);
    if(in==-1){
        err(1, "open");
    }
    int out = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0666);
    if(out==-1){
        err(1, "open");
    }

    ssize_t readSize;
    uint8_t start;
    while((readSize = read(in, &start, sizeof(uint8_t)))>0){
        if(start!=0x55){
            continue;
        }

        uint8_t n;
        if(read(in, &n, sizeof(uint8_t)) == -1){
            err(1, "read");
        }

        uint8_t data[n-2];
        if(read(in, data, sizeof(uint8_t)*(n-2)) == -1){
            err(1, "read");
        }

        uint8_t res = start ^ n;
        for(int i = 0; i<n-3;i++){
            res ^= data[i];
        }
        if(res!=data[n-3]){
            continue;
        }

        if(write(out, &start, sizeof(uint8_t))==-1){
            err(1, "write");
        }
        if(write(out, &n, sizeof(uint8_t))==-1){
            err(1, "write");
        }
        if(write(out, data, sizeof(uint8_t)*(n-2))==-1){
            err(1, "write");
        }
    }

    if(readSize == -1){
        err(1, "read");
    }

    close(in);
    close(out);
    return 0;
}