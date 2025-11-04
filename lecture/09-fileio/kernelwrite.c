#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  int fd = open("tmp", O_RDWR | O_CREAT, O_TRUNC | O_TRUNC, S_IRUSR | S_IWUSR);

  char *msg = "Hello, I hope this works well!\n";

  write(fd, msg, strlen(msg));
}
