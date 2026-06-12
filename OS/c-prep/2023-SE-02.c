#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
    if(argc != 4){
        errx(1, "argc");
    }

    const char* wanted = argv[1];

    int dict = open(argv[2], O_RDONLY);
    if(dict == -1){
        err(1, "open");
    }
    int idx = open(argv[3], O_RDONLY);
    if(idx == -1){
        err(1, "open");
    }

    struct stat st;
    if (fstat(idx, &st) == -1){
         err(1, "fstat");
    }
    int lines = st.st_size / sizeof(uint32_t);
    int start = 0;
    int end = lines-1;

    ssize_t readSize;
    while (start <= end){
        int mid = start + (end - start) / 2;
        if(lseek(idx, (off_t)mid * sizeof(uint32_t), SEEK_SET) == -1){
            err(1, "lseek");
        }
        uint32_t pos;
        if(read(idx, &pos, sizeof(uint32_t)) == -1){
            err(1, "read");
        }
        if(lseek(dict, pos +1, SEEK_SET) == -1){
            err(1, "lseek");
        }
        char word[63];
        int i =0;
        while(true){
            char c;
            if(read(dict,&c, sizeof(char) ) == -1){
                err(1, "read");
            }
            if(c == '\n'){
                break;
            }
            word[i] = c;
            i++;
        }
        word[i] = '\0';

        if(strcmp(wanted, word) == 0){
            while(true){
            char c;
            if(read(dict,&c, sizeof(char) ) == -1){
                err(1, "read");
            }
            if(c == '\0'){
                break;
            }
            if(write(1, &c, sizeof(char)) == -1){
                err(1, "write");
            }
            i++;
            }
            break;
        } else if (strcmp(wanted, word) > 0) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    close(dict);
    close(idx);
    return 0;
}