#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
 
#define MAXN 4
 
typedef struct _toggle {
  bool toggle[MAXN * MAXN];
  int num;
} Toggles;
 
void printToggles(Toggles *toggles, int N)
{
  for (int i = 0; i < N * N; i++)
    if (toggles->toggle[i])
      printf("%d ", i);
  printf("\n");
}
 
bool correct(Toggles *toggles, int N, int light[])
{
  int toggleNum[MAXN * MAXN] = {0};
 
  for (int i = 0; i < N * N; i++)
    if (toggles->toggle[i]) {
      toggleNum[i]++;
      if (i % N > 0)         /* left */
	toggleNum[i - 1]++;
      if (i % N < N - 1)    /* right */
	toggleNum[i + 1]++;
      if (i / N > 0)         /* up */
	toggleNum[i - N]++;
      if (i / N < N - 1)    /* down */
	toggleNum[i + N]++;
    }
 
  for (int i = 0; i < N * N; i++)
    if (((light[i] + toggleNum[i]) % 2) != 0)
      return false;
 
  return true;
}
 
void search(Toggles *toggles, Toggles *best, int level, int N, int light[])
{
  if (level == N * N) {
    if (correct(toggles, N, light) && toggles->num < best->num) 
      *best = *toggles;
    return;
  }
 
  toggles->num++;
  toggles->toggle[level] = true;
  search(toggles, best, level + 1, N, light);
  toggles->num--;
  toggles->toggle[level] = false;
 
  search(toggles, best, level + 1, N, light);
}
 
int main()
{
  int N;
  scanf("%d", &N);
  assert(N <= MAXN);
  int light[MAXN * MAXN] = {0};
  int index;
  while (scanf("%d", &index) != EOF)
    light[index] = 1;
 
  Toggles toggles;
  toggles.num = 0;
  for (int i = 0; i < N * N; i++)
    toggles.toggle[i] = false;
 
  Toggles best;
  best.num = N * N + 1;
 
  search(&toggles, &best, 0, N, light);
  printToggles(&best, N);
 
  return 0;
}
