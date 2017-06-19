#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 13

typedef struct
{
  int head;
  int tail;
  int queue[MAX_SIZE];
}Queue;
