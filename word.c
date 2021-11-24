#include <stdio.h>
#include <string.h>
 
int main()
{
  int threshold; scanf("%d", &threshold);
#ifdef DEBUG
  printf("%d\n", threshold);
#endif
  char word[200];
  int frequency[26][26] = 0;
  while (scanf("%s", word) == 1) {
#ifdef DEBUG
    printf("%s\n", word);
#endif
    int length = strlen(word);
    for (int i = 0; i < length - 1; i++)
      frequency[word[i] - 'a'][word[i + 1] - 'a']++;
  }
 
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++)
      printf("%d%c", frequency[i][j], j == 25? '\n' : ' ');
  }
 
  int max = -1, maxi, maxj;
  for (int i = 0; i < 26; i++) 
    for (int j = 0; j < 26; j++)
      if (frequency[i][j] > max) {
	maxi = i; 
	maxj = j;
	max = frequency[i][j];
      }
#ifdef DEBUG
  printf("%d %d\n", maxi, maxj);
#endif
  char answer[27];
  int used[26] = {0};
  answer[0] = 'a' + maxi;
  answer[1] = 'a' + maxj;
  used[maxi] = used[maxj] = 1;
  int answerIndex = 2;
 
  int index = maxj;
  int found = 1;
  while (found) {
    found = 0;
    max = -1;
    int maxi;
    for (int i = 0; i < 26; i++)
      if (!used[i] && frequency[index][i] > threshold && frequency[index][i] > max) {
	found = 1;
	max = frequency[index][i];
	maxi = i;
      }
    if (found) {
      index = maxi;
      answer[answerIndex++] = maxi + 'a';
      used[maxi] = 1;
    }
  }
  answer[answerIndex] = '\0';
  printf("%s\n", answer);
}
