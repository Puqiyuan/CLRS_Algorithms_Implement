/*
  Test result:
  pqy@sda1:~/.../chapter9$ ls
  min_max.c
  pqy@sda1:~/.../chapter9$ gcc min_max.c 
  pqy@sda1:~/.../chapter9$ ./a.out 
  Input the length of the array: 4 
  4 7 -1 10
  The minimum is -1, the maximum is 10.
  pqy@sda1:~/.../chapter9$
 */


#include <stdio.h>
#include <stdlib.h>

int min_max(int *A, int *res, int len)// Find the minimum and maximum of the integer array.
{
  int i;

  res[0] = res[1] = A[0];

  for (i = 1; i <= len - 1; i++)
    {
      if (res[0] > A[i])
	res[0] = A[i];

      if (res[1] < A[i])
	res[1] = A[i];
    }

  return 0;
}

int main(int argc, char *argv[])
{
  int res[2], len, i;
  printf("Input the length of the array: ");
  scanf("%d", &len);
  
  int *A = (int*)malloc(len * sizeof(int));

  for (i = 0; i <= len - 1; i++)
    scanf("%d", &A[i]);

  min_max(A, res, len);

  printf("The minimum is %d, the maximum is %d.\n", res[0], res[1]);
  
  return 0;
}
