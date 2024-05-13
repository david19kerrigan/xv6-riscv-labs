#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  char buf;
  int fd[2];

  pipe(fd);
  close(fd[1]);

  while(read(0, &buf, 1) > 0){
    char *word;
    char *words[];
    printf("%c\n", buf);
  }
  return 0;
}
