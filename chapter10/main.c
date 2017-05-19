/*
  Test result:
  pqy@sda1:~/.../chapter10$ gcc main.c                                                                    
  pqy@sda1:~/.../chapter10$ ./a.out 
  Test for stack_empty function: 1 the value of S.top: 0
  Push 34, 100, 199:
  Display: 
  The top of the stack: 3
  199 100 34 
  pop one element:
  The return element of pop: 199
  Display after pop:
  The top of the stack: 2
  100 34 
  pqy@sda1:~/.../chapter10$ 
  [pqy@sda1:0]  0:bash                                                       1.27 82% Fri 2017-05-19 11:24
 */

#include "stack.h"
#include "./lib/operation.c"

int main(int argc, char *argv[])
{
  Stack S;

  init_stack(&S);

  printf("Test for stack_empty function: %d the value of S.top: %d\n", stack_empty(S), S.top);

  printf("Push 34, 100, 199:\n");
  push(&S, 34);
  push(&S, 100);
  push(&S, 199);

  printf("Display: \n");
  disply(S);

  printf("pop one element:\n");
  int x = pop(&S);
  printf("The return element of pop: %d\n", x);
  printf("Display after pop:\n");
  disply(S);
    
  return 0;
}

