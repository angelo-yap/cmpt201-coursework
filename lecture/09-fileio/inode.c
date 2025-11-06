#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  char *buffer;

  printf("enter path\n");
  size_t len = 0;
  getline(&buffer, &len, stdin);

  buffer[strcspn(buffer, "\n")] = 0;

  struct stat sb;

  int status = stat(buffer, &sb);

  printf("ans: %d\n", status);

  if (S_ISREG(sb.st_mode))
    printf("Regular file\n");
  else if (S_ISDIR(sb.st_mode))
    printf("Directory\n");
  else
    printf("Other\n");
}
