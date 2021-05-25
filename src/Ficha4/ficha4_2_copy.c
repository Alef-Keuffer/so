#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main ()
{
  printf("%u\n", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
  printf("%u\n", S_IRUSR);
  printf("%u\n",S_IWUSR );
  printf("%u\n", S_IRGRP );
  printf("%u\n",  S_IWGRP );
  printf ("%u\n", S_IROTH);
  int i_fd = open ("/etc/passwd", O_RDONLY);
  int o_fd = open ("saida.txt", O_CREAT | O_RDWR, 436);
  int e_fd = open ("erros.txt", O_CREAT | O_RDWR, 958);
  // 400 ^ 200 ^ ((400 ^ 200) >> 3) ^ (400 >>3 >>3)
  // 666 = 436 = 958
  // -rw-rw-r--
  //int e_fd = open ("erros.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
  //printf("%d\n", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
  dup2 (i_fd, STDIN_FILENO);
  dup2 (o_fd, STDOUT_FILENO);
  dup2 (e_fd, STDERR_FILENO);

  close (i_fd);
  close (e_fd);
  close (o_fd);

  int n_lines = 10;
  char c;
  for (int i = 0; i < n_lines;)
	{
	  c = (char)getchar ();
	  if (c == '\n')
		i++;
	  putchar(c);
	}
  return 0;
}
