#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char* merge_string (char a[], char b[])
{
  char static new[2048];
  int c = 0;
  for (int i = 0; a[i] != 0; new[c++] = a[i++]);
  for (int i = 0; b[i] != 0; new[c++] = b[i++]);
  new[c] = 0;
  return new;
}

char *convert_argv_to_v (int argc, char *argv[])
{
  char static new[2048];
  int c = 0;
  for (int i = 1; i < argc; i++)
	{
	  for (int j = 0; argv[i][j] != 0; j++)
		new[c++] = argv[i][j];
	  if (i < argc - 1)
		new[c++] = ' ';
	}
  new[c] = 0;
  return new;
}

int call_program (int argc, char **argv){
	char *build_path (const char *str, ...) __attribute__((__sentinel__(0)));
  	char *path = "/home/alef/Documents/coding/c/so/cmake-build-debug/./";
  	char *command1 = merge_string(path,convert_argv_to_v(argc, argv));
  	printf("%s\n",command1);
  	char *args[] = {command1, NULL};
	//execle (argv[1],(char *const) exec_argv, env, (char *)NULL);
	execvp (args[0], args);
	system("ls -l");
	return 0;
}

int main (int argc, char *argv[])
{
  int status = system("./foo 1 2 3");
  call_program(argc, argv);
//  char *string1 = "Hello";
//  char *string2 = "Darling";
//  char *merged = merge_string(string1, string2);
//  printf("%s\n", merged);
  return 0;
}
