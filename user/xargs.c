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
  int i = 0;
  while(read(0, &buf, 1) > 0){
    *word++ = buf;
    if(buf == ' '){
      *--word = 0;
      printf("word: (%s)\n", start);
      array[i] = "";
      memcpy(array[i], start, word-start);
      printf("arr: (%s)\n", array[i]);
      start = word;
    }
  }
  free(word);
  free(array);
  return 0;
}
