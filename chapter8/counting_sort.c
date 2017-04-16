/*
  test result:

  pqy@sda1:~/.../chapter8$ gcc counting_sort.c 
  pqy@sda1:~/.../chapter8$ ./a.out 
  0 0 2 2 3 3 3 5
 */
#include <stdio.h>
#include <stdlib.h>


int counting_sort(int *A, int *B, int k, int len)//The main function that implement
//counting sort. B array is the sorted elements lie on. A array is waiting for sorting.
//k is the largest value in A array, and len is the length of array A.
{
  int i, j;
  int *C = (int*)malloc((k + 1) * sizeof(int));//C is a auxiliary array for describing
  //that for each element in array A how many elements smaller than it.

  for (i = 0; i <= k; i++)
    C[i] = 0;

  for (j = 0; j <= len - 1; j++)
    C[A[j]] = C[A[j]] + 1;//every time when we increment one if there is a element in array A
  //correspond index of C array. Until now, for value of C array, is representing that how many
  //elements in A array that equal to index of this value.

  for (i = 1; i <= k; i++)
    C[i] = C[i] + C[i - 1];//Because of the index of C is increasing, obviously. So until now,
  //the value of C array representing how many elements in A array that smaller than index of
  //this value.

  for (j = len - 1; j >= 0; j--)//Now we should to decide which position is belong to value in
    //A array. And put the element to B array.
    {
      B[C[A[j]] - 1] = A[j];
      C[A[j]] = C[A[j]] - 1;//if there are same element in array A, we should put the latter on the
      //left
    }

  return 0;
}


int main(int argc, char *argv[])
{
  int A[8] = {2, 5, 3, 0, 2, 3, 0, 3};
  int B[8], i;

  counting_sort(A, B, 5, 8);

  for (i = 0; i <= 7; i++)
    printf("%d ", B[i]);

  printf("\n");
    
  return 0;
}

