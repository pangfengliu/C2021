#include <stdio.h>
int main()
{
  int a;
  scanf("%d", &a);
  int h;
  h = a / 100;
  a = a - h * 100;
  int t;
  t = a / 10;
  a = a - t * 10;
  int i;
  i = a;
  printf("%d\n", h);
  printf("%d\n", t);
  printf("%d\n", i);
}
