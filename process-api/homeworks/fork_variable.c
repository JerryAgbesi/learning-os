#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  int x = 500;
  printf("Before fork: x = %d (pid:%d)\n", x, (int)getpid());

  int rc = fork();
  if (rc < 0)
  {
    // fork failed
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    // child process
    printf("Child initial: x = %d (pid:%d)\n", x, (int)getpid());
    x = 200;
    printf("Child modified: x = %d (pid:%d)\n", x, (int)getpid());
  }
  else
  {
    // parent process
    int rc_wait = wait(NULL);
    printf("Parent initial: x = %d (pid:%d)\n", x, (int)getpid());
    x = 300;
    printf("Parent modified: x = %d (pid:%d)\n", x, (int)getpid());
  }

  printf("Final value of x = %d (pid:%d)\n", x, (int)getpid());
  return 0;
}
