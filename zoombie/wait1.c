#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid,wpid;
	int status;
	pid =fork();
	if(pid==0)
	{
		printf("---child--- childID: %d\n",getpid());
        sleep(10);
		printf("child die!!!\n");
		return 73;
	}
	else if(pid>0)
	{
		//wpid=wait(NULL);//不关心怎么结束的
		wpid = wait(&status);//等待子进程先结束(如果子进程未中止，父进程阻塞在这个函数处)
		if(wpid==-1)
		{
			perror("wait error");
			exit(1);
		}
		if(WIFEXITED(status))//判断 子进程正常退出判断
		{
			printf("child exit with %d\n",WEXITSTATUS(status));
			printf("------parent  finish\n");
		}
		if(WIFSIGNALED(status))//判断 子进程异常退出判断
		{
			printf("child exit with%d\n",WTERMSIG(status));
		}
	}
	else
	{
		perror("fork");
		return 1;
	}
	
}
