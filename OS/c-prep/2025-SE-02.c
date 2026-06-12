#include <err.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    if (argc != 4){
        errx(1, "args");
    }

    int index = open(argv[1], O_RDONLY);
    if(index==-1){
        err(1, "open");
    }

    int values = open(argv[2], O_RDONLY);
    if(values==-1){
        err(1, "open");
    }

    struct stat st;
    fstat(values, &st);

    if(st.st_size %4 != 0){
        errx(1, "invalid values");
    }

    uint8_t byte;
    ssize_t readSize;
    int position = 0;
    bool found = false;

    while ((readSize = read(index, &byte, 1))>0){
        uint8_t typeBit = byte & (1 << 7);
        uint8_t nameSize = byte & ~(1 << 7);

        char name[UINT8_T MAX  +1];
        if(read(index, name, nameSize) == -1){
            err(1, "read");
        }

        name[nameSize] = '\0';

        if(strcmp(argv[3], name) == 0){
            if (lseek(values, position*4, SEEK_SET) == -1){
                err(1, "lseek");
            }
            char buf[1024];

            if(typeBit == 0){
                uint32_t value;
                if(read(values, &value, sizeof(value)) == -1){
                    err(1, "read");
                }

                snprintf(buf, sizeof(buf), "%d\n", value);
            } else {
                float value;
                if(read(values, &value, sizeof(value)) == -1){
                    err(1, "read");
                }

                snprintf(buf, sizeof(buf), "%.3f\n", value);
            }

            write(1, buf, strlen(buf));

            found = true;
            break;
        }
        position++;
    }
    if(readSize == -1){
        err(1, "read");
    }

    if(!found){
        errx(1, "value not found");
    }

    close(values);
    close(index);
    return 0;
}