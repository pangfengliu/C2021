#include <stdio.h>
#include <string.h>
 
#define WORDLEN 10000
 
void fillPlus(char word[], int index, int position[])
{
  for (int i = ((index > 0)? position[index - 1] + 1 : 0); i <= position[index]; i++)
    word[i] = '+';
}
 
void printOthers(char word[], int i, int j, int position[])
{
  char toPrint[WORDLEN];
  strcpy(toPrint, word);
  fillPlus(toPrint, i, position);
  fillPlus(toPrint, j, position);
  printf("%s\n", toPrint);
}
 
void printSyllable(char word[], int index, int position[])
{
  char toPrint[WORDLEN];
  for (int i = 0; i < strlen(word); i++)
    toPrint[i] = '+';
  toPrint[strlen(word)] = '\0';
 
  if (index > 0) {
    int start = position[index - 1] + 1;
    strncpy(toPrint + start, word + start, position[index] - position[index - 1]);
  } else             /* == 0 */
    strncpy(toPrint, word, position[index] + 1);
 
  printf("%s\n", toPrint);
}
 
void findVowel(char word[], int position[])
{
  char *vowel = "aeiou";
  int length = strlen(word);
  int count = 0;
  for (int i = 0; i < length; i++)
    if (strchr(vowel, word[i]) != NULL) 
      position[count++] = i;
}
 
int main()
{
  char word[WORDLEN];
  int position[WORDLEN];
  int i, j;
  while(scanf("%s%d%d", word, &i, &j) != EOF) {
    findVowel(word, position);
    printSyllable(word, i, position);
    printSyllable(word, j, position);
    printOthers(word, i, j, position);
  }
}
