#include <stdio.h>
#include <stdbool.h>
 
#define DPS 0
#define HEALER 1
#define TANK 2
#define CLASS 3
 
#define QUEUE 5000
 
int main()
{
  int start[CLASS] = {0};
  int length[CLASS] = {0};
  int queue[CLASS][QUEUE];
  int numP[CLASS] = {3, 1, 1};
 
  int id;
  while (scanf("%d", &id) != EOF) {
    int class = id % CLASS;
    queue[class][start[class] + length[class]] = id;
    length[class]++;
 
    bool party = true;
    for (int c = 0; c < CLASS; c++)
      if (length[c] < numP[c])
	party = false;
 
    if (party) {
      for (int c = 0; c < CLASS; c++)
	for (int p = 0; p < numP[c]; p++) {
	  printf("%d ", queue[c][start[c]]);
	  start[c]++;
	  length[c]--;
	}
      printf("\n");
    }
#ifdef DEBUG
    printf("%d %d\n", id, class);
#endif
  }
  return 0;
}
