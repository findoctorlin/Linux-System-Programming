#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

pid_t fork(void);

int main()
{
  pid_t pid;	//pid_t约等于整数类型
  int x=1;

  pid = fork();
  if (pid == 0)
  {
    printf("child: x=%d\n", ++x);
  }

  printf("parent: x=%d\n", --x);
  printf("childPID=%d\n", pid);
  printf("End Of File\n");
  return 0;
}
