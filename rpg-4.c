#include <stdio.h>
#include <stdbool.h>
 
#define DPS 0
#define HEALER 1
#define TANK 2
#define CLASS 3
 
#define QUEUE 5000
 
bool enoughPlayer(int length[], int numP[])
{
  for (int c = 0; c < CLASS; c++)
    if (length[c] < numP[c])
      return false;
  return true;
}
 
int main()
{
  int start[CLASS] = {0};
  int length[CLASS] = {0};
  int queue[CLASS][QUEUE];
  int numP[CLASS] = {3, 1, 1};
 
  int id;
  while (scanf("%d", &id) != EOF) {
    int class = id % CLASS;
    queue[class][(start[class] + length[class]) % QUEUE] = id;
    length[class]++;
 
    if (enoughPlayer(length, numP)) {
      for (int c = 0; c < CLASS; c++)
	for (int p = 0; p < numP[c]; p++) {
	  printf("%d%c", queue[c][start[c] % QUEUE], 
		 (p == numP[c] - 1 && c == CLASS -1)? '\n' : ' ');
	  start[c]++;
	  length[c]--;
	}
    }
  }
  return 0;
}
