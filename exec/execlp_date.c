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
        execlp("date", "date", NULL);
    }
    else if (pid > 0) {           
        sleep(0.8);
        printf("I am parent process: %d, you can do sth more here\n", getpid());
    }    
    
    return 0;  
} 
