#include <sys/wait.h> // for wait()
#include <unistd.h> // for fork()
#include <stdio.h> // for fprintf()

/**
 * @brief Cria (dez) filhos em profundidade.
 *
 * Cada processo imprime seu PID e o PID de seu pai.
 *
 * O programa vai até o 10º nível de profundidade.
 */
int main() {
	int status;
	int nFilhos = 10;
	/* The starting process. */
	fprintf(stderr, "My father's PID: %d\nMy PID: %d\nIteration: %d\n\n", getppid(), getpid(), -1);
	/* Creation of nFilhos process. */
	for (int i = 0; i < nFilhos; i++) {
		if (fork() == 0) {// Child does something
			fprintf(stderr, "My father's PID: %d\nMy PID: %d\nIteration: %d\n\n", getppid(), getpid(), i);
		} else {// Parent does something
			pid_t terminated = wait(&status);
			fprintf(stderr, "[Pai (my PID is %d)] process %d. Exit with code %d\nIteration: %d\n\n",
					getpid(), terminated, WEXITSTATUS(status), i);
			_exit(0);
		}
	}
	return 0;
}
