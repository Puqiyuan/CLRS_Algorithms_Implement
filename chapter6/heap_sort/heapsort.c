/*
  The test result:
  pqy@sda1:~/.../heap_sort$ ./a.out 
  the length of the array:10 
  input the elements of array:
  67 23 9 1 9 100 34 89 0 2
  After sorted:
  0 1 2 9 9 23 34 67 89 100
 */


#include <stdio.h>
#include <stdlib.h>

int left(int i)// return left child  of node i
{
  return 2 * i;
}

int right(int i)//return right child of node i
{
  return 2 * i + 1;
}

int max_heapify(int *A, int i, int heap_size)
{
  int l = left(i);
  int r = right(i);
  int largest, tem;
  
  if (l <= heap_size && A[l] > A[i])// if the left child larger than node i
    {
      largest = l;
    }

  else
    largest = i;

  if (r <= heap_size && A[r] > A[largest])// if the right child larger than node i
    largest = r;

  if (largest != i)// the largest will always be the index of the largest node.
    {
      tem = A[i];
      A[i] = A[largest];
      A[largest] = tem;

      max_heapify(A, largest, heap_size);
    }

  return 0;
}


int build_max_heap(int *A)
{
  int i, heap_size = A[0];

  for (i = A[0] / 2; i >= 1; i--)// start with A[0], because max heap is nearly complete binary tree
                                 // the leaf begin with A[0] / 2.
    max_heapify(A, i, heap_size);
  
  return 0;
}


int heapsort(int *A)
{
  int i, tem, heap_size = A[0];
  
  build_max_heap(A);
  for ( i = A[0]; i >= 2; i--)
    {
      tem = A[1];               //the root always be the largest value at current max heap.
      A[1] = A[i];              //so move it backward, we want an increasing sort.
      A[i] = tem;
      heap_size--;
      max_heapify(A, 1, heap_size);//change node may don't keep max heap property
    }
  
  return 0;  
}


int show(int *A)// display the array
{
  int i = 1;

  for (i = 1; i <= A[0]; i++)
    printf("%d ", A[i]);

  printf("\n");

  return 0;
}


int main(int argc, char *argv[])
{
  int len, i;
  int *A;
  printf("the length of the array:");
  scanf("%d", &len);
  
  A = (int*)malloc((len + 1) * sizeof(int));
  A[0] = len; //at index 0, the value is the length of the array

  printf("input the elements of array:\n");
  for (i = 1; i <= len; i++)
    scanf("%d", &A[i]);

  heapsort(A);

  printf("After sorted:\n");
  show(A);
  
  return 0;
}
