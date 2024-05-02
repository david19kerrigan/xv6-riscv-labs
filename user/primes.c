#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int start = 2;
int end = 35;

int main(int argc, char *argv[]){
  int parent_pipe[2];
  pipe(parent_pipe);

  write(parent_pipe[1], &start, 1);
  for(int i = start; i <= end; ++i){
    write(parent_pipe[1], &i, 1);
  }
  close(parent_pipe[1]);
  pipeline(&parent_pipe);
}

void pipeline(int *parent_pipe[]){
  if(fork() == 0){
    int child_pipe[2];
    pipe(child_pipe);
    int buf;
    read(parent_pipe[0], &buf, 1);
    int divisor = buf;
    if(divisor >= end){
      close(child_pipe[1]);
      exit(0);
    }

    printf("%d divisor\n", divisor);
    int next = divisor + 1;
    write(child_pipe[1], &next, 1);

    while(read(parent_pipe[0], &buf, 1) > 0){
      if(divisor == buf) printf("%d prime\n", divisor);
      else if(buf % divisor != 0){
        printf("%d write\n", buf);
        write(child_pipe[1], &buf, 1);
      }
    }
    close(child_pipe[1]);
    close(parent_pipe[0]);
    pipeline(&child_pipe);
    exit(0);
  } else {
    wait(0);
    exit(0);
  }
}
