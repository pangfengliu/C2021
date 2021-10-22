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

  int last2 = -1;
  int dist2 = -1;
  int maxdist2 = -1;
  int secondmaxdist2 = -1;
  int second2start, second2end;
  int max2start, max2end;

  int last3 = -1;
  int dist3 = -1;
  int maxdist3 = -1;
  int secondmaxdist3 = -1;
  int second3start, second3end;
  int max3start, max3end;

  while (scanf("%d", &n) != EOF) {
    switch (n) {
    case 1:
      if (last1 >= 0) 		/* not the first */
	dist1 = index - last1;

      if (dist1 > maxdist1) {
	secondmaxdist1 = maxdist1;
	second1start = max1start;
	second1end = max1end;
	maxdist1 = dist1;
	max1start = last1;
	max1end = index;
      } else if (dist1 == maxdist1) {
	maxdist1 = dist1;
	max1start = last1;
	max1end = index;
      } else if (dist1 >= secondmaxdist1) {
	secondmaxdist1 = dist1;
	second1start = last1;
	second1end = index;
      }
#ifdef DEBUG1
      printf("index %d dist1 %d maxdist1 %d secondmaxdist1 %d\n",
	     index, dist1, maxdist1, secondmaxdist1);
      printf("max start %d end %d second start %d end %d\n\n",
	     max1start, max1end, second1start, second1end);
#endif
      last1 = index;
      break;

    case 2:
      if (last2 >= 0) 		/* not the first */
	dist2 = index - last2;

      if (dist2 > maxdist2) {
	secondmaxdist2 = maxdist2;
	second2start = max2start;
	second2end = max2end;
	maxdist2 = dist2;
	max2start = last2;
	max2end = index;
      } else if (dist2 == maxdist2) {
	maxdist2 = dist2;
	max2start = last2;
	max2end = index;
      } else if (dist2 >= secondmaxdist2) {
	secondmaxdist2 = dist2;
	second2start = last2;
	second2end = index;
      }
#ifdef DEBUG2
      printf("index %d dist2 %d maxdist2 %d secondmaxdist2 %d\n",
	     index, dist2, maxdist2, secondmaxdist2);
      printf("max start %d end %d second start %d end %d\n\n",
	     max2start, max2end, second2start, second2end);
#endif
      last2 = index;
      break;
      
    case 3:
      if (last3 >= 0) 		/* not the first */
	dist3 = index - last3;

      if (dist3 > maxdist3) {
	secondmaxdist3 = maxdist3;
	second3start = max3start;
	second3end = max3end;
	maxdist3 = dist3;
	max3start = last3;
	max3end = index;
      } else if (dist3 == maxdist3) {
	maxdist3 = dist3;
	max3start = last3;
	max3end = index;
      } else if (dist3 >= secondmaxdist3) {
	secondmaxdist3 = dist3;
	second3start = last3;
	second3end = index;
      }
#ifdef DEBUG3
      printf("index %d dist3 %d maxdist3 %d secondmaxdist3 %d\n",
	     index, dist3, maxdist3, secondmaxdist3);
      printf("max start %d end %d second start %d end %d\n\n",
	     max3start, max3end, second3start, second3end);
#endif
      last3 = index;
      break;

    }
    index++;
  }

  printf("%d %d %d\n", secondmaxdist1, second1start, second1end);
  printf("%d %d %d\n", secondmaxdist2, second2start, second2end);
  printf("%d %d %d\n", secondmaxdist3, second3start, second3end);
  return 0;
}
