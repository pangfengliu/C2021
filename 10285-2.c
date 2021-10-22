#include <stdio.h>
#define N 3

int main()
{
  int n;
  int index = 0;

  int last[] = {-1, -1, -1};
  int dist[] = {-1, -1, -1};
  int maxdist[] = {-1, -1, -1};
  int secondmaxdist[] = {-1, -1, -1};
  int secondstart[N], secondend[N];
  int maxstart[N], maxend[N];

  while (scanf("%d", &n) != EOF) {
    n--;			/* 0, 1, 2 */
    if (last[n] >= 0) 		/* not the first */
      dist[n] = index - last[n];

    if (dist[n] > maxdist[n]) {
      secondmaxdist[n] = maxdist[n];
      secondstart[n] = maxstart[n];
      secondend[n] = maxend[n];
      maxdist[n] = dist[n];
      maxstart[n] = last[n];
      maxend[n] = index;
    } else if (dist[n] == maxdist[n]) {
      maxdist[n] = dist[n];
      maxstart[n] = last[n];
      maxend[n] = index;
    } else if (dist[n] >= secondmaxdist[n]) {
      secondmaxdist[n] = dist[n];
      secondstart[n] = last[n];
      secondend[n] = index;
    }
    last[n] = index;
    index++;
  }

  for (int i = 0; i < N; i++)
    printf("%d %d %d\n", secondmaxdist[i], secondstart[i], secondend[i]);
  return 0;
}
