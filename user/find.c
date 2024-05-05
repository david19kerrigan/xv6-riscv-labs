#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  struct stat st;
  struct dirent de;
  char buf[512];

  int fd = open(".", 0);
  fstat(fd, &st);
  stat(buf, &st);
  while(read(fd, &de, 1)){
  }

  close(fd);
  exit(0);
}
