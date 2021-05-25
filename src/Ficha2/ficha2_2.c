#include <unistd.h>
#include "pid.h"

int main(void) {
  fork();
  print_child_report ();
  return 0;
}
