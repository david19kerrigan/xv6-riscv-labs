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
      char buf[512], *new_path;
      strcpy(buf, path);
      new_path = buf + strlen(buf);
      *new_path++ = '/';
      memmove(new_path, de.name, DIRSIZ);
      new_path[DIRSIZ] = 0;
      stat(buf, &st);

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
  find(".", argv[1]);
}
