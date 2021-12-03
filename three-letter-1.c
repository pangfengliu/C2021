#include <stdio.h>

#define N 100000

int main()
{
  char word[N + 1];
  while (scanf("%s", word) != EOF) {
    puts(word);
  }
  return 0;
}
