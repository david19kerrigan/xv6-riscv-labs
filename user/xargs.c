#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  char buf;
  char *word = (char*)malloc(512);
  char **array = (char**)malloc(512);
  char *start = word;

  if(argc < 2){
    return 0;
  }

  array[0] = argv[0];
  int j = 2;
  int i = 1;
  while(argv[j] > 0){
    array[i] = (char*)malloc(512);
    memcpy(array[i], argv[j], sizeof(argv[j]));
    i++;
    j++;
  }

  while(read(0, &buf, 1) > 0){
    *word++ = buf;
    if(buf == ' '){
      *--word = 0;
      array[i] = (char*)malloc(512);
      memcpy(array[i++], start, word-start);
      start = word;
    }
  }

  *--word = 0;
  array[i] = (char*)malloc(512);
  memcpy(array[i], start, word-start);

  if(fork() == 0){
    printf("test: (%s)\n", array[2]);
    exec(argv[1], array);
  } else{
    wait(0);
  }

  free(word);
  i = 0;
  while(array[i] > 0){
    free(array[i++]);
  }
  free(array);
  return 0;
}
