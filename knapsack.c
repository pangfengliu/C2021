#include <stdio.h>
 
int max(int a, int b)
{
  return (a > b? a : b);
}
 
void maxValue(const int W, const int i, const int n, 
	      const int weight[], const int value[], 
	      const int currentVal, int *maxVal)
{
  if (i >= n || W == 0) 
    *maxVal = max(currentVal, *maxVal);
  else {
    maxValue(W, i + 1, n, weight, value, currentVal, maxVal);
    if (weight[i] <= W)
      maxValue(W - weight[i], i + 1, n, weight, value, 
	       currentVal + value[i], maxVal);
  }
}
 
int main()
{
  int n, W;
  scanf("%d%d", &n, &W);
  int weight[n], value[n];
  for (int i = 0; i < n; i++) 
    scanf("%d%d", &(weight[i]), &(value[i]));
  int maxVal = 0;
  maxValue(W, 0, n, weight, value, 0, &maxVal);
  printf("%d\n", maxVal);
  return 0;
}
