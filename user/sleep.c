#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc <= 1 || argc >= 3){
    printf("Incorrect number of arguments\n");
    exit(1);
  }
  sleep(atoi(argv[1]));
  exit(0);
}
