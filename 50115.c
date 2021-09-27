#include <stdio.h>

int main()
{
  int a, b, h, c, d;
  scanf("%d%d%d%d%d", &a, &b, &h, &c, &d);
  int volume = a * b * h;
  int area = a * b - c * d;
  int depth = volume / area;
  printf("%d\n", depth);
  return 0;
}
