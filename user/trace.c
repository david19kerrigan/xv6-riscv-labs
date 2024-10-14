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

  //trace((int) *argv[1]);
  char **array = (char**)malloc(512);
  for(int i = 3; i < argc; ++i){
    array[i-3] = (char*)malloc(512);
    memcpy(array[i-3], argv[i], sizeof(argv[i]));
  }

  char *test[3] = {"echo", "hello", 0};
  exec("echo", test);

  exit(0);
}
