#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define NumKeyword 4

bool cyclomatic(char word[])
{
  char *keyword[NumKeyword] = {"if", "while", "for", "case"};
  for (int i = 0; i < NumKeyword; i++)
    if (strcmp(word, keyword[i]) == 0)
      return true;
  return false;
}

int main()
{
  int cyclomaticNum = 0;
  int c;
  c = getchar();
  while (c != EOF) {
#ifdef PRINTC
    putchar(c);
#endif
    if (c == '?') {
      cyclomaticNum++;
      c = getchar();
    }
    else if (isalpha(c)) {
      char word[128];
      int index = 0;
      do {
	word[index++] = c;
	c = getchar();
      } while (isalnum(c) || c == '_');
      word[index++] = '\0';
      if (cyclomatic(word))
	cyclomaticNum++;
    } else
      c = getchar();      
  }
  printf("%d\n", cyclomaticNum);
  return 0;
}
