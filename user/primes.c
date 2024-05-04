#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int start = 2;
int end = 35;

int pipeline(int parent_pipe[2], int start){
  if(fork() == 0){
    int child_pipe[2];
    pipe(child_pipe);
    int buf;
    if(start >= end){
      close(child_pipe[1]);
      return 0;
    }

    while(read(parent_pipe[0], &buf, 1) > 0){
      if(start == buf) printf("%d prime\n", start);
      else if(buf % start != 0){
        write(child_pipe[1], &buf, 1);
      }
    }
    close(child_pipe[1]);
    close(parent_pipe[0]);
    return pipeline(child_pipe, start + 1);
  } else{
    wait(0);
    return 0;
  }
}

int main(int argc, char *argv[]){
  int parent_pipe[2];
  pipe(parent_pipe);

  for(int i = start; i <= end; ++i){
    write(parent_pipe[1], &i, 1);
  }
  close(parent_pipe[1]);
  return pipeline(parent_pipe, 2);
}

