#include "stack.h"
#include "./lib/operation.c"

int main(int argc, char *argv[])
{
  Stack S;

  init_stack(&S);

  printf("Test for stack_empty function: %d the value of S.top: %d\n", stack_empty(S), S.top);
  
  return 0;
}

