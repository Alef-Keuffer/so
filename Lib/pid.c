#include <stdio.h>
#include <unistd.h>
#include "pid.h"

int print_pid (void)
{
  printf ("My PID: %d\n", getpid ());
  return 0;
}
int print_father (void)
{
  printf ("My father's PID: %d\n", getppid ());
  return 0;
}
int print_child_report (void)
{
	  fprintf (stderr, "My father's PID: %d\nMy PID: %d\n", getppid (), getpid ());
  return 0;
}

int print_father_report (pid_t pid, int exit_code)
{
  fprintf (stderr, "Filho %d saiu com código %d\n", pid, exit_code);
  return 0;
}
