#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc < 2){
    printf("Usage: trace flag command args\n");
    exit(1);
  }

  trace((int) *argv[1]);

  if(fork() == 0){
    exec(argv[2], &argv[2]);
  } else{
    wait(0);
  }

  trace(0);

  exit(0);
}
