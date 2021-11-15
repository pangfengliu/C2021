#include <stdio.h>
#include <string.h>
 
#define DELIMETER "*"
#define N 10
 
int minNumChar(int numChar[], int length)
{
  int minChar = 50000000;
  int index;
 
  for (int i = 0; i < length; i++)
    if (numChar[i] < minChar) {
      minChar = numChar[i];
      index = i;
    }
  return index;
}
 
void splitAndMap(char*** ptr, char* str)
{
  int length = 0;
  while (ptr[length] != NULL)
    length++;
 
  int numChar[N] = {0};
  int index[N] = {0};
 
  char *token;
  token = strtok(str, DELIMETER);
  while (token != NULL) {
#ifdef DEBUG
    printf("%s\n", token);
#endif
    int minIndex = minNumChar(numChar, length);
 
    numChar[minIndex] += strlen(token);
    ptr[minIndex][index[minIndex]] = token;
    // *(*(ptr + minIndex) + *(index + minIndex)) = token;
    index[minIndex]++;
 
    token = strtok(NULL, DELIMETER);
  }
}
