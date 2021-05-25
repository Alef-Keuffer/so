#include <unistd.h>
#include <stdio.h>

int main(void){
  int ret;
  //Como ls é uma váriavel de ambiente, não é precisso dar o caminho completo
  ret = execl("/bin/ls", "ls", "-l", "-a", NULL);
  printf("Se tudo ocorreu bem, esse printf nunca acontece\n");
  perror("Erro");
  return ret;
}
