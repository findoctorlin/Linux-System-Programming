#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  printf("before fork\n");
  pid_t pid = fork();	//pid_t约等于整数类型

  if (pid == 0) {
    printf("child is created\n");
    }
  else if(pid > 0) {
    printf("parent: My childPID is: %d\n", pid);
    }

  printf("End Of File\n");
  return 0;
}
