#include <err.h>
#include <fcntl.h>
#include <stdint.h>
#include <sys/stat.h>
#include <unistd.h>


typedef struct Triple{
    uint16_t offset;
    uint8_t len;
    uint8_t idk;
} Triple;

int main(int argc, char* argv[]){
    if(argc != 5){
        errx(1, "argc");
    }

    int f1dat = open(argv[1], O_RDONLY);
    if(f1dat == -1){
        err(1, "open");
    }

    int f1idx = open(argv[2], O_RDONLY);
    if(f1idx == -1){
        err(1, "open");
    }

    int f2dat = open(argv[3], O_WRONLY | O_TRUNC | O_CREAT, 0666);
    if(f2dat == -1){
        err(1, "open");
    }

    int f2idx = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0666);
    if(f2idx == -1){
        err(1, "open");
    }

    ssize_t readSize;
    Triple t;
    uint16_t newOffset = 0;
    while((readSize = read(f1idx, &t, sizeof(Triple)) )>0){
        uint8_t buf[4096];

        if(lseek(f1dat, t.offset, SEEK_SET) == -1){
            err(1, "lseek");
        }

        if(read(f1dat, buf, t.len) == -1){
            err(1, "read");
        }

        if(buf[0]< 0x41 || buf[0]>0x5A){
            continue;
        }

        if(write(f2dat, buf, t.len) == -1){
            err(1, "write");
        }

        Triple newT = { newOffset, t.len, 0};
        if(write(f2idx, &newT,sizeof(Triple)) == -1){
            err(1, "write");
        }

        newOffset+=t.len;
    }

    if(readSize == -1){
        err(1, "read");
    }

    close(f1dat);
    close(f1idx);
    close(f2idx);
    close(f2dat);
    return 0;
}