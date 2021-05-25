#include <unistd.h>

int main (int argc, char *argv[]){
  char *path = "/home/alef/Documents/coding/c/so/cmake-build-debug/./ficha3_3";
  execvp (path, argv);
  return 0;
}
