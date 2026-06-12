#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    if(argc != 3){
        errx(1, "argc");
    }

    int in = open(argv[1], O_RDONLY);
    if(in == -1){
        err(1, "open");
    }

    int out = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0666);
    if(out == -1){
        err(1, "open");
    }

    ssize_t readSize;
    uint8_t byte;
    while((readSize = read(in, &byte, sizof(uint8_t)))>0){
        uint16_t encoded = 0;
        
        for(int i = 7; i >=0; i--){
            uint8_t bit = (byte >> i) & i;
            encoded <<= 2;
            if (bit == 1){
                encoded |= 0b10;
            } else{
                encoded |= 0b01;
            }
        }

        if(write(out, &encoded, sizeof(uint16_t)) == -1){
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