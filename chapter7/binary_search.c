/*
  test result:
  pqy@sda1:~/.../chapter7$ gcc binary_search.c
  pqy@sda1:~/.../chapter7$ ./a.out 
  Please input the length of array: 5
  Please input the elements of array:
  1 23 78 123 9876
  Please input your search element: 1
  the location of the element is: 0
  pqy@sda1:~/.../chapter7$ ./a.out 
  Please input the length of array: 5
  Please input the elements of array:
  -99 234 788 909 1234
  Please input your search element: 1234
  the location of the element is: 4
  pqy@sda1:~/.../chapter7$ ./a.out 
  Please input the length of array: 2
  Please input the elements of array:
  -100 678
  Please input your search element: 679
  the location of the element is: -1
 */


#include <stdio.h>
#include <stdlib.h>

int bin_search(int *A, int n, int x)
{
  int left = 0; int right = n - 1;

  while(left <= right)
    {
      int middle = (left + right) / 2;
      if (x == A[middle])
	return middle;

      if (x > A[middle])
	left = middle + 1;

      else
	right = middle - 1;
    }

  return -1;
}


int main(int argc, char *argv[])
{
  int *A, len, i, x, location;

  printf("Please input the length of array: ");
  scanf("%d", &len);

  A = (int*)malloc(len * sizeof(int));

  printf("Please input the elements of array:\n");
  
  for (i = 0; i <= len - 1; i++)
    scanf("%d", &A[i]);

  printf("Please input your search element: ");
  scanf("%d", &x);

  location = bin_search(A, len, x);
  printf("the location of the element is: %d\n", location);
  return 0;
}
