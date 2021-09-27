#include <stdio.h>

int main()
{
  int x;
  scanf("%d", &x);
  printf("%d\n%d\n%d\n", x / 100, (x / 10) % 10, x % 10);
  return 0;
}
