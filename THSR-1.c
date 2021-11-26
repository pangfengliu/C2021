#include <stdio.h>
#include <stdbool.h>
 
#define SEATS 5
#define ROWS 20
#define CARS 1000
 
#define TOTALSEATS (CARS * ROWS * SEATS)
 
void printSeat(int seat)
{
  printf("%d %d %d ", seat / (SEATS * ROWS) + 1, 
	 (seat / SEATS) % ROWS + 1, seat % SEATS + 1);
}
 
int main()
{
  int car;                    
  scanf("%d", &car);
  int nextS = 0;
  int nextD = 0;
  bool free[TOTALSEATS];
 
  for (int i = 0; i < TOTALSEATS; i++)
    free[i] = true;
 
  int request;
  while (scanf("%d", &request) != EOF) {
    switch (request) {
    case 1:
      while (!free[nextS])
	nextS++;
      free[nextS] = false;
      printSeat(nextS);
      printf("\n");
      break;
    case 2:
      while (!((nextD + 1 < car * ROWS * SEATS) && 
 
	       ((nextD % SEATS == 0) || (nextD % SEATS == 1) || (nextD % SEATS == 3))
	       && free[nextD] && free[nextD + 1]))
	nextD++;
      free[nextD] = free[nextD + 1] = false;
      printSeat(nextD);
      printSeat(nextD + 1);
      printf("\n");
      break;
    }
#ifdef DEBUG
    printf("%d\n", request);
#endif
  }
  return 0;
}