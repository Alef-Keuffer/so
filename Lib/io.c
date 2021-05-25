#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

char* readln(int fd, ssize_t max){
  char b;
  char static new[2048];
  unsigned long c = 0;
  long l = 0;
  long r;
  while ((r = read(fd,&b,1)) == -1 && errno==EINTR){
	new[c++] = b;
    if (b == '\n'){
      break;
    }
  }
  return realloc(new,c);
}

char *convert_argv_to_v (int argc, char *argv[], int max)
{
  char static new[2048];
  int c = 0;
  for (int i = 0; i < max; i++)
  {
	for (int j = 0; argv[i][j] != 0; j++)
	  new[c++] = argv[i][j];
	if (i < argc - 1)
	  new[c++] = ' ';
  }
  new[c] = 0;
  return new;
}
