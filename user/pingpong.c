#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int p[2];
  char buf[1];
  pipe(p);
  if(fork() == 0){
    close(p[1]);
    read(p[0], buf, 1);

    printf("%d pong\n", getpid());
    write(p[1], "a", 1);
    exit(0);
  } else {
    printf("%d ping\n", getpid());
    close(p[0]);
    write(p[1], "a", 1);
    close(p[1]);

    wait(0);
    close(p[1]);
    read(p[0], buf, 1);
    exit(0);
  }
}
