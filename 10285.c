#include <stdio.h>

int main()
{
  int n;
  int index = 0;

  int last1 = -1;
  int dist1 = -1;
  int maxdist1 = -1;
  int secondmaxdist1 = -1;
  int second1start, second1end;
  int max1start, max1end;
  
  while (scanf("%d", &n) != EOF) {
    switch (n) {
    case 1:
      if (last1 >= 0) 		/* not the first */
	dist1 = index - last1;

      if (dist1 >= maxdist1) {
	secondmaxdist1 = maxdist1;
	second1start = max1start;
	second1end = max1end;

	maxdist1 = dist1;
	max1start = last1;
	max1end = index;
	
      } else if (dist1 >= secondmaxdist1) {
	secondmaxdist1 = dist1;
	second1start = last1;
	second1end = index;
      }
#ifdef DEBUG
      printf("index %d dist1 %d maxdist1 %d secondmaxdist1 %d\n",
	     index, dist1, maxdist1, secondmaxdist1);
      printf("max start %d end %d second start %d end %d\n\n",
	     max1start, max1end, second1start, second1end);
#endif
      last1 = index;
      break;
      
    }
    index++;
  }

  printf("%d %d %d\n", secondmaxdist1, second1start, second1end);
  return 0;
}
