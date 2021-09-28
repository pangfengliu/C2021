#include <stdio.h>
#ifdef USEBOOL
#include <stdbool.h>
#endif

int main()
{
  int M;
  scanf("%d", &M);
  bool N = (M > 0) && (M % 2 == 0) && (M > 10000 || M < 1000);
  printf("%d\n", N);
  return 0;
}
