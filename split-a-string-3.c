#include <stdio.h>
#include <string.h>
#include <stdint.h>
 
#define DELIMETER "*"
#define N 10
 
int minNumChar(const int numChar[], const int length)
{
  int minChar = INT32_MAX;
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
    int minIndex = minNumChar(numChar, length);
 
    numChar[minIndex] += strlen(token);
    ptr[minIndex][index[minIndex]] = token;
    // *(*(ptr + minIndex) + *(index + minIndex)) = token;
    index[minIndex]++;
 
    token = strtok(NULL, DELIMETER);
  }
  for (int i = 0; i < length; i++)
    ptr[i][index[i]] = NULL;
  return;
}
