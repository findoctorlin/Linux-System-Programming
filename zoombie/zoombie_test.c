#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t pid, wpid;
    pid = fork();

    int status;

    if(pid == 0) {
        printf("---child---, my parentPID: %d, going to sleep 10s\n", getppid());
        sleep(10);
        printf("---child dead!!!---\n");
    }
    else if(pid > 0) {
        while(1) {
            wpid = wait(&status);
            if(wpid == -1) {
                perror("wait err\n");
                exit(1);
                }
                printf("I am parent, MyPID: %d, childPID: %d\n", getpid(), pid);
                sleep(1);
        }
    }
    else{
        peeor("fork");
        return 1;
    }
    return 0;
}
