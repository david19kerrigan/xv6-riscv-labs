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
    read(p[0], buf, 1);
    close(p[0]);
    printf("%d received %s\n", getpid(), buf);

    printf("%d pong\n", getpid());
    write(p[1], "b", 1);
    close(p[1]);
    exit(0);
  } else {
    printf("%d ping\n", getpid());
    write(p[1], "a", 1);
    close(p[1]);

    wait(0);
    read(p[0], buf, 1);
    close(p[0]);
    printf("%d received %s\n", getpid(), buf);
    exit(0);
  }
}
