#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
  for (int i = 1; i < argc; i++)
	{
	  for (int j = 0; argv[i][j] != 0; j++)
		write (STDOUT_FILENO, &argv[i][j], 1);
	  if (i < argc - 1)
		write (STDOUT_FILENO, " ", 1);
	}
  write (STDOUT_FILENO, "\n", 1);
  return 0;
}
