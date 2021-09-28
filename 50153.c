#include <stdio.h>

int main()
{
  int a, b, c, d, e, f;
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
  int perimeter = 2 * (a + b + c + d + e + f);
  int area = a * b + (a + c) * d + (a + c + e) * f;
  printf("%d\n%d\n" , perimeter, area);
  return 0;
}
