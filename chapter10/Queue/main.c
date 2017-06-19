#include "queue.h"
#include "./lib/operation.c"

int main(int argc, char *argv[])
{
  Queue Q;

  init_queue(&Q);
  printf("Q -> head: %d, Q -> tail: %d\n", Q.head, Q.tail);

  int data[12] = {12, 2, 3, 4, 78, 1, 0, 34, 13, 799, 5, 1000}, i;

  for (i = 0; i <= 11; i++)
    en_queue(&Q, data[i]);

  printf("Test 1:\n");
  printf("All elements:\n");
  display(Q);

  printf("Q -> head: %d, Q -> tail: %d\n", Q.head, Q.tail);

  printf("The return element of head: %d.\n", de_queue(&Q));

  printf("Test 2:\n");
  int x = 101;
  en_queue(&Q, x);
  
  return 0;
}
