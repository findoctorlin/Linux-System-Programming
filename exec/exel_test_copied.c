#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
#include <errno.h>  
#include <pthread.h>  
  
void sys_err(const char *str)  
{  
    perror(str);  
    exit(1);  
}  
int main(int argc, char *argv[])  
{    
    pid_t pid = fork();  

    if (pid == -1) {  
        sys_err("pipe error");  
        exit(1);
    }  
    else if (pid == 0) {
        printf("I just copied myself! check the folder!\n");
        execl("/home/yuhanlin/code/LinuxCodeLearning/file_IO_test/cp_function/fputc_demo2", "/home/yuhanlin/code/LinuxCodeLearning/file_IO_test/cp_function/fputc_demo2", "exel_test.c", "exel_test_copied.c", NULL);
    }
    else if (pid > 0) {           
        sleep(1);
        printf("I am parent process: %d, you can do sth more here\n", getpid());
    }    
    
    return 0;  
} 
