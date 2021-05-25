#include <string.h>
// tirei foto, checar screenshot

int main(char* command[]){
  int fork_ret, exec_ret, wait_ret, status, res;

  char *exec_args[1024];
  char*string;
  int i = 0;

  string = strtok(command, " ");
  while (string != NULL){
    exec_args[i] = string;
  }
}
