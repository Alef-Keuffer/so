#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main (void)
{
  int status;
  char *exec_args[] = {"", "-l", NULL};
  pid_t fork_ret = fork ();
  if (fork_ret == 0)
	{
	  fprintf (stderr, "PID do filho %d\n", getpid ());
	  int exec_ret = execvp ("/bin/ls", exec_args);
	  fprintf (stderr, "Se tudo ocorreu bem, esse printf nunca acontece\n");
	  perror ("Erro de exec");
	  _exit (exec_ret);
	}
  else
	{
	  fprintf (stderr, "PID do pai %d\n", getpid ());
	  int wait_ret = wait (&status);
	  fprintf (stderr, "O filho retornou %d\n", WEXITSTATUS(status));
	}
  return 0;
}
