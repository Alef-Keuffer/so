#include <sys/wait.h> // for wait()
#include <unistd.h> // for fork()
#include <stdio.h> // for fprintf()

/**
 * Programa que cria dez processos filhos que executam sequencialmente.
 *
 * @li Os filhos imprimem o seu PID e o do seu pai, e finalmente, terminam a sua execução.
 * @li O valor de saida de cada filho é igual ao seu numero de ordem
 * 	 (e.g.: primeiro filho criado termina com o valor 1).
 * @li O pai imprime o codigo de saida de cada um dos seus filhos.
 */
int main(void) {
	int status;
	int nFilhos = 10;
	for (int i = 0; i < nFilhos; i++) {
		if (fork() == 0) {// Child does something
			fprintf(stderr, "My father's PID: %d\nMy PID: %d\n\n", getppid(), getpid());
			_exit(i);
		} else {// Parent does something
			pid_t wait_ret = wait(&status);
			fprintf(stderr, "Filho %d saiu com código %d\n\n", wait_ret, WEXITSTATUS(status));
		}
	}
	return 0;
}
