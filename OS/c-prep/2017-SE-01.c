#include <err.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct Entry {
    uint16_t offset;
    uint8_t old;
    uint8_t new;
} Entry;

int main(int argc, char* argv[]){
    if(argc != 4){
        errx(1, "bad args");
    }

    int f1 = open(argv[1], O_RDONLY);
    if (f1 == -1){
        err(1, "%s", argv[1]);
    }

    int f2 = open(argv[2], O_RDONLY);
    if (f2 == -1){
        err(1, "%s", argv[2]);
    }

    struct stat st;
    if(fstat(f1, &st) == -1){
        err(1, "stat");
    }

    off_t f1Size = st.st_size;

    if (f1Size > UINT16_MAX){
        errx(1, "files too large (%ld>%d)", f1Size, UINT16_MAX);
    }

    if(fstat(f2, &st) == -1){
        err(1, "stat");
    }

    off_t f2Size = st.st_size;

    if(f1Size != f2Size){
        errx(1, "file sized differ (%ld>%ld)", f1Size, f2Size);
    }

    int patch = open(argv[3], O_WRONLY | O_TRUNC | O_CREAT, 0666);
    if(patch == -1){
        err(1, "%s", argv[3]);
    }

    uint8_t byteFromF1;
    ssize_t readSize;
    uint16_t offset = 0;

    while ((readSize = read(f1, &byteFromF1, 1)) > 0){
        uint8_t byteFromF2;
        if(read(f2, &byteFromF2, 1) == -1){
            err(1, "read");
        }

        if(byteFromF1 != byteFromF2){
            Entry e;
            e.offset = offset;
            e.old = byteFromF1;
            e.new = byteFromF2;

            if(write(patch, &e, sizeof(Entry)) == -1){
                err(1, "write");
            }
        }

        offset++;
    }

    if (readSize == -1){
        err(1, "read");
    }

    close(patch);
    close(f2);
    close(f1);
}