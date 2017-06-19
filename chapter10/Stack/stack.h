#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct
{
  int top;

  int stack[MAX_SIZE];
}Stack;
