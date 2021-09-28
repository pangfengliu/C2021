#include <stdio.h>

int main()
{
  int sum, foot, tail;
  scanf("%d%d%d", &sum, &foot, &tail);
  int crab = sum - tail;
  int chicken = (tail * 4 - (foot - 8 * crab)) / 2;
  int rabbit = sum - chicken - crab;
  printf("%d\n%d\n%d\n", chicken, rabbit, crab);
  return 0;
}
  
