#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main ()
{
  int i_fd = open ("/etc/passwd", O_RDONLY);
  int o_fd = open ("saida.txt", O_CREAT | O_RDWR, 0666);
  int e_fd = open ("erros.txt", O_CREAT | O_RDWR, 0666);

  dup2 (i_fd, STDIN_FILENO);
  dup2 (o_fd, STDOUT_FILENO);
  dup2 (e_fd, STDERR_FILENO);

  close (i_fd);
  close (e_fd);
  close (o_fd);

  int n_lines = 10;
  char buffer;
  char line[1024];
  int i = 0;
  while (n_lines > 0)
	{
	  while (read (0, &buffer, 1) != 0)
		{
		  line[i] = buffer;
		  i++;
		  if (buffer == '\n')
			{
			  break;
			}
		}
	  write (1, line, i);
	  write (2, line, i);
	  i = 0;
	  n_lines--;
	}
  return 0;
}
