/*
  test result:
  pqy@sda1:~/.../chapter7$ ./a.out 
  Please input the length of the array: 8
  Please input the elements of the array:
  2 8 7 1 3 5 6 4
  After sorting:
  1 2 3 4 5 6 7 8
 */


#include <stdio.h>
#include <stdlib.h>

int partition(int *A, int p, int r);

int quick_sort(int *A, int p, int r)
{
  int q;
  
  if (p < r)
    {
      q = partition(A, p, r);
      quick_sort(A, p, q - 1);
      quick_sort(A, q + 1, r);
    }

  return 0;
}


int partition(int *A, int p, int r)
{
  int x = A[r], i = p - 1, j, tmp1, tmp2;

  for (j = p; j <= r - 1; j++)
    {
      if (A[j] <= x)
	{
	  i++;
	  tmp1 = A[i];
	  A[i] = A[j];
	  A[j] = tmp1;
	}
    }

  tmp2 = A[i + 1];
  A[i + 1] = A[r];
  A[r] = tmp2;

  return i + 1;
}


int show(int *A, int len)
{
  int i;

  for (i = 0; i <= len - 1; i++)
    printf("%d ", A[i]);
  printf("\n");

  return 0;
}


int main(int argc, char *argv[])
{
  int *A, n, i;

  printf("Please input the length of the array: ");
  scanf("%d", &n);
  
  A = (int*)malloc(n * sizeof(int));
  printf("Please input the elements of the array:\n");
  
  for (i = 0; i <= n - 1; i++)
    scanf("%d", &A[i]);

  quick_sort(A, 0, n-1);
  printf("After sorting:\n");
  show(A, n);
  
  return 0;
}
