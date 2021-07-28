#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t pid, wpid;

    int status;
    pid = fork();

    if(pid == 0) {
        printf("---child---, my parentPID: %d, childID: %d going to sleep 10s\n", getppid(), getpid());
        sleep(10);
        printf("---child dead!!!---\n");
    }
    else if(pid > 0) {
        wpid = wait(&status);//address pass, 如果参数非 NULL，则可以输出子进程终止状态; 等待10秒以后子进程死亡，回收之
        if(wpid == -1){
            perror("wait error\n");
            exit(1);
        }
        printf("parent wait finish\n");
        printf("Terminated childID: %d\n", wpid);
    }
    else{
        perror("fork");
        return 1;
    }
    return 0;
}
