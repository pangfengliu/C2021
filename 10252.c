#include <stdio.h>
 
#define MAXPOINT 100
#define NOTFOUND -1
 
int main()
{
  int N;
  scanf("%d", &N);
 
  int location[MAXPOINT + 1];
  for (int i = 1; i <= MAXPOINT; i++)
    location[i] = NOTFOUND;
 
  int point;
  for (int i = 0; i < N; i++) {
    scanf("%d", &point);
    if (location[point] == NOTFOUND) {
      location[point] = i;
      printf("%d\n", i);
    } else {
      printf("%d %d %d\n", i, location[point], point);
      location[point] = NOTFOUND;
    }
  }
  return 0;
}
