#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
//fd: 文件描述符
int main(int argc, char* argv[])
{
    char buf[1024];
    int n = 0;
    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_CREAT | O_RDWR | O_TRUNC, 0644);

    while((n = read(fd1, buf, 1024)) != 0) {
        write(fd2, buf, n);
    }
    close(fd1);
    close(fd2);

    printf("orginal file descriptor: %d\n", fd1);
    printf("orginal file descriptor: %d\n", fd2);
    return 0;
}