#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main() {
  printf("SERVER!\n");

  // socket
  int socket_fd = socket(AF_UNIX, SOCK_DGRAM, 0);
  if (socket_fd == -1) {
    perror("Socket Failed");
    exit(EXIT_FAILURE);
  }

  // remove existing socket (if any);
  if (remove("socket_fun") == -1 && errno != ENOENT) {
    perror("Remove failed");
    exit(EXIT_FAILURE);
  }

  // bind
  struct sockaddr_un sockstruct;
  sockstruct.sun_family = AF_UNIX;
  snprintf(sockstruct.sun_path, 108, "da_udp_socket");
  if (bind(socket_fd, (struct sockaddr *)&sockstruct,
           sizeof(struct sockaddr_un)) == -1) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // accept
  while (true) {

    // read
    const int SIZE = 1024;
    char buff[SIZE];

    struct sockaddr_un return_address;
    socklen_t retaddr_size = sizeof(struct sockaddr_un);
    memset(&return_address, 0, sizeof(struct sockaddr_un));

    ssize_t ans = recvfrom(socket_fd, buff, SIZE, 0,
                           (struct sockaddr *)&return_address, &retaddr_size);

    int bytes_read;

    if (ans == -1) {
      perror("recvfrom");
      exit(EXIT_FAILURE);
    }
    write(STDOUT_FILENO, buff, ans);
  }

  // lcose
  close(socket_fd);
}
