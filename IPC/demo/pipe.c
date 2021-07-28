#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void sys_err(const char* str)
{
    perror(str);
    exit(1);
}

int main(int argc, int* argv[]) 
{
    int ret;
    pid_t pid;
    int fd[2];
    char* str = "Hello I am Pipepiper\n";
    char buf[1024];

    ret = pipe(fd);

    if(ret == -1) sys_err("pipe error");

    pid = fork();

    if(pid > 0) {
        close(fd[0]);   //关闭父进程的r端
        write(fd[1], str, strlen(str));
        sleep(1);       //防止父进程提前结束
        close(fd[1]);   //父进程完成w操作后, 关闭w
    }
    else if(pid == 0) {
        close(fd[1]);   //关闭父进程的w端
        ret = read(fd[0], buf, sizeof(buf));    //先从buff读
        write(STDOUT_FILENO, buf, ret);           //再写到输出设备STDOUT_FILENO
        close(fd[0]);
    }
    return 0;
}