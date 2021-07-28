#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
//测试getpid()和getppid()函数: getpid返回当前进程标识，getppid返回父进程标识
int main()
{
  printf("---before fork---\n");
  pid_t pid = fork();

  if (pid == 0) {
    printf("---child process---: MyPID=%d, parentPID=%d\n", getpid(), getppid());
    }
  else if(pid > 0) {
    printf("---parent process---: MyPID=%d, childPID=%d, parentPID=%d\n", getpid(), pid, getppid());
    }

  printf("End Of File\n");
  return 0;
}
