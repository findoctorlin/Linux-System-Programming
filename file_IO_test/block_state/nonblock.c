#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char buf[10];
    int n;

    n = read(STDIN_FILENO, buf, 10);    //#define STDIN_FILENO 0 代表输入设备(键盘)的文件描述符 
    if(n < 0) {
        perror("read STDIN_FILENO");
        exit(1);
    }
    write(STDOUT_FILENO, buf, n);   //#define STDIN_FILENO 1 代表输出设备(显示器)的文件描述符

    return 0;
}