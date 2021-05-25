#include "ficha2.h"

void create_ten_children() {
  int id, i;
  for (id = fork(), i = 0; id != 0 && i < 9; wait(NULL), i++, id = fork());
  wait(NULL);
  print_child_report ();
}

int create_ten_children_return() {
  int i, id = fork();
  for (i = 0; id != 0 && i < 9; i++) {
    wait(NULL);
    id = fork();
  }
  wait(NULL);
  print_child_report ();
  return i;
}

void exerc3_v2() {
  int i, status, id;
  for (i = 1; i < 11; i++) {
    id = fork();
    if (!id) {
		print_child_report ();
      _exit(i);
    }
    wait(&status);
    printf("Father talking, exit code of this child is %d\n", WEXITSTATUS(status));
  }
  print_child_report ();
}
void exerc3() {
  int i, status, id;
  for (id = fork(), wait(&status), i = 1; id != 0 && i < 10; id = fork(), wait(&status), i++)
    printf("Father talking, exit code of this child is %d\n", WEXITSTATUS(status));
  if (id)
    printf("Father talking, exit code of this child is %d\n", WEXITSTATUS(status));
  print_child_report ();
  _exit(i);
}

void exerc4() {
  int i, id, status, child_id;
  for (id = fork(), i = 1; id != 0 && i < 10; id = fork(), i++);
  while (id && (child_id = wait(&status)) > 0)
    printf("Father talking, exit code of child %d is %d\n", child_id, WEXITSTATUS(status));
  printf("%d\n", i);
  _exit(i);
}

int exerc5() {
  int status;
  int nFilhos = 10;
  print_child_report ();
  for (int i = 0; i < nFilhos; i++) {
    if (fork() == 0) {
		print_child_report ();
    } else {
      pid_t terminated = wait(&status);
      printf("[Pai] process %d. Exit with code %d\n", terminated, WEXITSTATUS(status));
      _exit(0);
    }
  }
  return 0;
}

int extra(){
  ssize_t res = 0;
  int fd, pid, status;
  char buff;
  fd = open("test.txt", O_CREAT | O_RDWR, 0666);
  res = write(fd, "abcd", 4);
  if((pid = fork()) == 0){
    res = write(fd, "efghAA", 6);
    _exit(res); // Implicit conversion (only accepts up to 8 bits, i.e. 255); future: use pipes
  }
  else{
    int child = wait(&status);
    lseek(fd, - WEXITSTATUS(child), SEEK_CUR);
    while((res = read(fd, &buff, 1)) > 0){
      write(1, &buff, 1);
    }
  }
  close(fd);
  int i = unlink("test.txt"); //Apaga o ficheiro
  return i;
}