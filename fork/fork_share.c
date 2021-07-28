#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int var = 0;

int main()
{
  printf("before fork\n");
  pid_t pid = fork();
  int var = 3;

  if(pid > 0) {
    // var = 1;
    printf("---parent---, var=%d\n", var);
    printf("My childPID is: %d, My PID is: %d\n", pid, getpid());
    }
  else if (pid == 0) {
    var = 2;
    printf("---child---, var=%d\n", var);
    printf("My ParentPID is: %d, My PID is: %d\n", getppid(), getpid());
    }

  printf("End Of File\n");
  return 0;
}
