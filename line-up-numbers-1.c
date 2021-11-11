#include <stdio.h> 
void merge(int A[], int B[], int* a[], int* b[])
{
  int indexA = 0, indexB = 0;
  int **last = NULL;
  int lastOn;
 
  do {
    if (A[indexA] < B[indexB]) {
      if (last != NULL)
	(*last) = &(A[indexA]);
      last = &(a[indexA]);
      lastOn = 0;
      indexA++;
    } else {
      if (last != NULL)
	(*last) = &(B[indexB]);
      last = &(b[indexB]);
      lastOn = 1;
      indexB++;
    }
  } while (*last != NULL);
 
  *last = (lastOn == 1)? &(A[indexA]) : &(B[indexB]);
}
