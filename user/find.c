#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fs.h"
#include "user/user.h"

int find(char *path, char *name){
  struct dirent de;
  struct stat st;

  int fd = open(path, 0);
  fstat(fd, &st);

  if(st.type == T_DIR){
    while(read(fd, &de, sizeof(de))){
      if(de.inum == 0 || strcmp(de.name, ".") == 0 || strcmp(de.name, "..") == 0) continue;
      char buf[512], *p;
      strcpy(buf, path);
      p = buf + strlen(buf);
      *p++ = '/';
      memmove(p, de.name, DIRSIZ);
      p[DIRSIZ] = 0;

      if(strcmp(de.name, name) == 0){
        printf("%s\n", buf);
      }
      if(fork() == 0){
        return find(buf, name);
      }
    }
  } 

  close(fd);
  return 0;
}

int main(int argc, char *argv[]){
  if(argc < 3 || argc > 3){
    printf("Incorrect arguments\n");
    exit(0);
  }
  find(argv[1], argv[2]);
}
