#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("%d\n", getpid());
  printf("%d\n", getppid());
  int temp = fork();
  if (temp) {
    printf("PARENT: PID=%d, child PID=%d\n", getpid(), temp);
  } else {
    printf("CHILD: PID=%d, parent PID=%d\n", getpid(), getppid());
  }
  sleep(3);
}
