#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    if(argc != 4){
        errx(1, "argc");
    }

    int scl = open(argv[1], O_RDONLY);
    if (scl == -1){
        err(1, "open");
    }
    int sdl = open(argv[2], O_RDONLY);
    if (sdl == -1){
        err(1, "open");
    }
    int f1 = open(argv[3], O_WRONLY | O_TRUNC | O_CREAT, 0666);
    if (f1 == -1){
        err(1, "open");
    }

    ssize_t readSize;
    uint8_t danger;
    while((readSize = read(scl, &danger, 1 ))>0){
        uint16_t buf;
        if(read(sdl, &buf, sizeof(uint16_t)) == -1){
            err(1, "read");
        }
        if(danger == 1){
            if(write(f1, &buf, sizeof(uint16_t)) == -1){
                err(1, "write");
            }
        }
    }

    if(readSize == -1){
        err(1, "read");
    }

    close(scl);
    close(sdl);
    close(f1);
    return 0;
}