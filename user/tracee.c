#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  //if(argc < 2){
    //printf("Usage: trace flag command args\n");
    //exit(1);
  //}

  //trace((int) *argv[1]);

  //char **array = (char**)malloc(512);
  //for(int i = 3; i < argc; ++i){
    //array[i-3] = (char*)malloc(512);
    //memcpy(array[i-3], argv[i], sizeof(argv[i]));
  //}

  char* test[2] = {"hi", 0};
  exec("echo", test);

  //if(fork() == 0){
    //char* test[2]; 
    //test[0] = "hi";
    //test[1] = 0;
    //exec("echo", test);
  //} else{
    //wait(0);
  //}

  //for(int i = 3; i < argc; ++i){
    //free(array[i-3]);
  //}
  //free(array);

  return 0;
}
