#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>  
#include <unistd.h>  
#include <errno.h>  
#include <pthread.h>
#include <fcntl.h>

void sys_err(const char *str)  
{  
	perror(str);  
	exit(1);  
}  

int main(int argc, char *argv[])
{
    char buf[4096];
    int fd;
    if(argc < 2) {      //说明只有一个参数就是该程序自身，需要在terminal添加参数传入main
        printf("Enter like this ./a.out fifoname\n");//argv[0]存放main.out，argc初始为1
        return -1;
    }

    fd = open(argv[1], O_RDONLY);   //将已有的fifo文件传入参数:argv[1], 打开该fifo管道
    if(fd < 0)
        sys_err("open");
    
    int len;
    while(1) {
        len = read(fd, buf, sizeof(buf));    //读（here fifo管道文件）中的数据
        write(STDOUT_FILENO, buf, len);      //将数据写到屏幕
        sleep(1);
    }
    close(fd);
    return 0;
}