#include <unistd.h>
#include <sys/wait.h>
#include "pid.h"
// Implemente um programa que execute concorrentemente uma lista de executaveis especificados como
// argumentos da linha de comando. Considere os executaveis sem quaisquer argumentos próprios.
// O programa devera esperar pelo fim da execução de todos processos por si criados.

int main (int argc, char *argv[])
{
  int status;
  for (int i = 1; i < argc; i++)
	{
	  if (fork () == 0)
		{
		  print_child_report();
		  execlp (argv[i], argv[i], NULL);
		  _exit (0);
		}
	}
  for (int i = 1; i < argc; i++)
	{
	  wait (&status);
	}
  return 0;
}
