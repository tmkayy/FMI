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
    uint16_t byte;

    while((readSize = read(in, &byte, sizeof(uint16_t))) > 0){
        uint8_t decoded = 0;
        for(int i = 7; i>=0; i--){
            int pair = (byte >> i*2) & 3;
            decoded <<= 1;

            if (pair == 2) { 
                decoded |= 1;
            } else if (pair == 1) {
                decoded |= 0;
            } else {
                errx(1, "invalid pair");
            }
        }
        if(write(out, &decoded, sizeof(uint8_t)) == -1){
            err(1, "Write");
        }
    }

    if (readSize == -1){
        err(1, "read");
    }

    close(in);
    close(out);
    return 0;
}