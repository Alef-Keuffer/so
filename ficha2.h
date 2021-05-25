
#ifndef SO__FICHA2_H
#define SO__FICHA2_H
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>
#include <stdio.h>
#include "Lib/pid.h"
void create_ten_children(void);
void exec2(void);
int create_ten_children_return(void);
_Noreturn void exerc3(void);
void exerc3_v2(void);
_Noreturn void exerc4(void);
int exerc5(void);
int extra(void);
#endif //SO__FICHA2_H
