#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, int* argv[]) {
    int fd1 = open(argv[1], O_RDWR);
    int fd2 = open(argv[2], O_RDWR);
    int fdret = dup2(fd1, fd2);
    printf("fdret = %d\n", fdret);

    int ret = write(fd2, "Trying to write sth into here\n", 30);    //利用fd2往fd1文件写值
    printf("ret = %d\n", ret);
    return 0; 
}