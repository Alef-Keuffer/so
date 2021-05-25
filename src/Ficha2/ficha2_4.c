#include <sys/wait.h> // for wait()
#include <unistd.h> // for fork()
#include <stdio.h> // for fprintf()

/**
 * Cria dez processos filhos em concorrência.
 *
 * O pai espera pelo fim da execução de todos os filhos,
   imprimindo os respectivos códigos de saída.
 */
int main(void) {
	int status;
	int nFilhos = 10;
	for (int i = 0; i < nFilhos; i++) {// Child does something
		if (fork() == 0) {
			fprintf(stderr, "My father's PID: %d\nMy PID: %d\n\n", getppid(), getpid());
			_exit(i);
		}
	}
	/* Parent waits each child and prints than immediately */
	for (int _ = 0; _ < nFilhos; _++) {//Parent does something
		pid_t wait_ret = wait(&status);
		fprintf(stderr, "Filho %d acabou com código %d\n\n", wait_ret, WEXITSTATUS(status));
	}
	return 0;
}
