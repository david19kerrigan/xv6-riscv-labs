#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  struct stat st;
  char buf[512];
  int fd = open(".", 0);
  fstat(fd, &st);
  stat(buf, &st);
  printf("%s", fmtname(buf));
  printf("here\n");
  close(fd);
  exit(0);
}
