#include <stdio.h>
 
int insert(int *ptr, int *ptrTable[], int frequency[], int object[], int count)
{
  for (int i = 0; i < count; i++)
    if (ptr == ptrTable[i]) {
      frequency[i]++;
      return count;
    }
  /* not found */
  ptrTable[count] = ptr;
  frequency[count] = 1;
  object[count] = *ptr;
  return count + 1;
}
 
void sort(int frequency[], int object[], int count)
{
  for (int i = count - 2; i >= 0; i--)
    for (int j = 0; j <= i; j++)
      if (frequency[j] > frequency[j + 1] || 
	  (frequency[j] == frequency[j + 1] && object[j] > object[j + 1])) {
	int temp = frequency[j];
	frequency[j] = frequency[j + 1];
	frequency[j + 1] = temp;
	temp = object[j];
	object[j] = object[j + 1];
	object[j + 1] = temp;
      }
}
 
void count(int **p[])
{
  int *ptrTable[512];
  int count = 0;
  int frequency[512];
  int object[512];
 
  for (int i = 0; p[i] != NULL; i++) 
    count = insert(*p[i], ptrTable, frequency, object, count);
 
  sort(frequency, object, count);
 
  for (int i = 0; i < count; i++)
    printf("%d %d\n", object[i], frequency[i]); 
 
}
