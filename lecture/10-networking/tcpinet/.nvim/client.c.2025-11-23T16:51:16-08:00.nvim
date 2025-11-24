#define _POSIX_C_SOURCE 200908L
// client
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main() {
  printf("CLIENT:\n");
  // socket
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    perror("Socket failed");
    exit(EXIT_FAILURE);
  }

  // connect
  struct sockaddr_in sockstruct;
  memset(&sockstruct, 0, sizeof(struct sockaddr_in));
  sockstruct.sin_family = AF_INET;
  sockstruct.sin_port = htons(1042);
  int ret = inet_pton(AF_INET, "127.0.0.1", &sockstruct.sin_addr);
  if (ret == -1) {
    perror("inet_pton");
    exit(EXIT_FAILURE);
  }

  if (connect(socket_fd, (struct sockaddr *)&sockstruct,
              sizeof(struct sockaddr_in)) == -1) {
    perror("connect failed");
    exit(EXIT_FAILURE);
  }
  // write
  char *msg = "Sockets are not fun (and Hello World).";
  int bytes_written = write(socket_fd, msg, strlen(msg));
  if (bytes_written == -1) {
    perror("write");
    exit(EXIT_FAILURE);
  }
  // close
  close(socket_fd);
  return 0;
}
