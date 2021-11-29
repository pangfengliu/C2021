#include <stdio.h>

#define MAXN 100000
#define W 3

int maxW(int a[], int b[])
{
  int maxv = -1, maxi;
  for (int i = 0; i < W; i++)
    if (a[i] + b[i] > maxv) {
      maxv = a[i] + b[i];
      maxi = i;
    }
  return maxi;
}

#define P 4

int main()
{
  int n;
  scanf("%d", &n);

  int bottom[4][W] = {{-1, 0, 0}, {0, 0, -1}, {0, 0, 0}, {-1, 0, -1}};
  int extra[4][W][W] = {{{1, 1, 0}, {2, 2, 1}, {2, 2, 1}},
			{{1, 2, 2}, {1, 2, 2}, {0, 1, 1}},
			{{1, 2, 1}, {1, 2, 1}, {1, 2, 1}},
			{{1, 1, 1}, {2, 2, 2}, {1, 1, 1}}};
  int col, type;
  int height[MAXN] = {0};
  while (scanf("%d%d", &col, &type) != EOF) {
    int stuck = maxW(&(height[col]), bottom[type]);
    int stuckH = height[col + stuck];
    for (int i = 0; i < W; i++)
      height[col + i] = stuckH + extra[type][stuck][i];
  }
  for (int i = 0; i < n; i++)
    printf("%d%c", height[i], (i == n - 1)? '\n' : ' ');
  return 0;
}
