#include "getrand.h"

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int getrand() {
  int random_fd = open("/dev/random", O_RDONLY);
  if (random_fd == -1) {
    printf("%s\n", strerror(errno));
  }
  int ret;
  int num_read = read(random_fd, &ret, sizeof(ret));
  close(random_fd);
  return ret;
}
