#include <err.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    if (argc != 3){
        errx(1, "bad args");
    }

    int src = open(argv[1], O_RDONLY);
    if (src == -1){
        err(1, "cant open src");
    }

    int dest = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0666);
    if (dest == -1){
        err(1, "cant open dest");
    }

    //read()>0; number of bytes
    //read() == 0; eof
    //read() == -1; error

    char buf[4096];
    ssize_t readSize;

    while ((readSize = read(src, &buf, sizeof(buf)))>0) {
        if(write(dest, &buf, readSize) == -1){
            err(1, "cant write");
        }
    }

    if (readSize == -1){
        err(1, "cant read");
    }

    close(dest);
    close(src);

    return 0;
}
