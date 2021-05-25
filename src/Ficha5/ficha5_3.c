#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_LINE_SIZE 1024

ssize_t readln(int fildes, void *buf, size_t nbyte) {

  ssize_t res = 0;
  int i = 0;

  while (i < nbyte && (res = read(fildes, &buf[i], 1)) > 0) {

	if (((char *)buf)[i] == '\n') {
	  return i + 1;
	}
	i += res;
  }

  return i;
}

int main(int argc, char *argv[]) {

  ssize_t res = 0;
  int p[2];
  char buffer[MAX_LINE_SIZE];
  int pid;
  int status;

  if (pipe(p) != 0) {
	perror("pipe");
	return -1;
  }

  switch ((pid = fork())) {
	case -1: perror("fork");
	  return -1;
	case 0: close(p[1]);
	  dup2(p[0], 0);
	  close(p[0]);
	  res = execlp("wc", "wc", NULL);
	  _exit(0);

	default: close(p[0]);
	  close(1);

	  while ((res = readln(0, buffer, MAX_LINE_SIZE)) > 0) {
		write(p[1], buffer, res);
	  }
	  close(p[1]);

	  if (wait(&status) < 0) {
		perror("wait");
		return -1;
	  }
	  if (status < 0) {
		perror("Filho");
	  }
  }
  return 0;
}
