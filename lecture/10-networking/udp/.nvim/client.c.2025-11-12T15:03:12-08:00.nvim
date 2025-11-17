#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main() {
  printf("CLIENT:\n");

  // socket
  int socket_fd = socket(AF_UNIX, SOCK_DGRAM, 0);
  if (socket_fd == -1) {
    perror("Socket Failed!");
    exit(EXIT_FAILURE);
  }

  // Create destination address
  struct sockaddr_un addr;
  memset(&addr, 0, sizeof(struct sockaddr_un));
  addr.sun_family = AF_UNIX;
  snprintf(addr.sun_path, 108, "da_udp_socket");

  // write
  char *msg = "I'm sending this; hope you get it.\n";
  int bytes_written =
      sendto(socket_fd, msg, strlen(msg), 0, (struct sockaddr *)&addr,
             sizeof(struct sockaddr_un));
  if (bytes_written == -1) {
    perror("write");
    exit(EXIT_FAILURE);
  }

  // close
  close(socket_fd);
  return 0;
}
