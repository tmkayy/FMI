#include <err.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct Node{
    uint64_t next;
    uint8_t user_data[504];
} Node;

int main(int argc, char* argv[]){
    if(argc!=2){
        errx(1, "bad args");
    }
    
    int fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        err(1, "%s", argv[1]);
    }

    struct stat st;

    if(fstat(fd, &st) == -1){
        err(1, "stat");
    }

    if (st.st_size == 0) {
        errx(1, "no entries in list");
    }

    if (st.st_size % sizeof(Node) != 0) {
        errx(1, "not a list");
    }

    char tempname[] = "./tempXXXXX";
    int temp = mkstemp(tempname);
    if(temp == -1){
        err(1, "mkstemp");
    }

    uint64_t nodeIndex = 0;
    uint64_t arrSize = 0;

    do{
        if(lseek(temp, nodeIndex, SEEK_SET) == -1){
            err(1, "lseek");
        }
        bool found = true;
        if(write(temp, &found, 1) == -1){
            err(1, "write");
        }

        if(nodeIndex > arrSize){
            arrSize = nodeIndex;
        }

        Node node;
        if(lseek(fd, nodeIndex * sizeof(Node), SEEK_SET) == -1){
            err(1, "lseek");
        }
        if (read(fd, &node, sizeof(Node)) == -1){
            err(1, "read");
        }
        nodeIndex = node.next;
    }while (nodeIndex != 0);

    ssize_t readSize;
    bool found;
    uint64_t index = 0;
    uint8_t zero[sizeof(Node)];
    memset(zero, 0, sizeof(Node));
    lseek(temp, 0, SEEK_SET);
    
    while((readSize = read (temp, &found, 1)) > 0){
        if (!found){
            if(lseek(fd, index * sizeof(Node), SEEK_SET) == -1){
                err(1, "lseek");
            }
            if(write(fd, &zero, sizeof(Node)) == -1){
                err(1, "write");
            }
        }
        index++;
    }

    if (readSize == -1) {
        err(1, "read");
    }

    for(uint64_t i = arrSize+1 ; i< st.st_size / sizeof(Node); i++){
        if (lseek(fd, i*sizeof(Node), SEEK_SET) == -1){
            err(1, "lseek");
        }
        if(write(fd, &zero, sizeof(Node)) == -1){
            err(1, "write");
        }
    }

    close(fd);
    return 0;
}