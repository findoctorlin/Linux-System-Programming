#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;  
    // fd = open("./dict.txt", O_RDONLY);
    fd = open("./dict1.txt",O_RDONLY | O_CREAT | O_TRUNC,0644);    //创建新文件，3个形参，rw-r--r--; 如果文件已存在, TRUNC函数把内容清空
    printf("fd = %d\n", fd);
    close(fd);  //关闭文件描述符
    // write(fd,text,strlen(buf));
    return 0;
}
