#include <stdio.h>

int main()
{
  int a, b, c, d, e, f, g;
  scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
  int ae = a * e;
  int be = b * e;
  int ce = c * e;
  int cf = c * f;
  int df = d * f;
  int eg = e * g;
  int edge = a + b + c + d + (ae + be + ce + cf + df) + eg + f + g;
  printf("%d\n", edge);

  int path = (ae + be + ce) * g + (cf + df);
  printf("%d\n", path);
  return 0;
}
