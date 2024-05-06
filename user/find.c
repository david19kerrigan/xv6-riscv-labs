#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fs.h"
#include "user/user.h"

int find(char *path, char *name){
  if(fork() == 0){
    struct dirent de;
    struct stat st;

    int fd = open(path, 0);
    fstat(fd, &st);
    if(st.type == T_DIR){
      while(read(fd, &de, sizeof(de))){
        if(de.inum == 0) continue;
        printf("%s %d\n", de.name, st.type);
        //char buf[512], *new_path;
        //new_path = buf + strlen(buf);
        //*new_path++ = '/';
        //stat(buf, &st);
        //memcpy(new_path, de.name, DIRSIZ);
        //new_path[DIRSIZ] = 0;
        close(fd);
        return find(path, name);
      }
    }

    close(fd);
    return 0;
  } else {
    wait(0);
    return 0;
  }
}

int main(int argc, char *argv[]){
  find(".", "test");
}
