#include <stdio.h>

int main()
{
  int n, i;
  scanf("%d%d", &n, &i);
  int power = 1;
  switch (i) {
  case 5: 
    power *= n;
    i--;
  case 4:
    power *= n;
  case 3:
    i--;
    power *= n;
  case 2:
    power *= n;
    i--;
  case 1:
    power *= n;
    i--;
  }
  printf("%d\n", power);
  return 0;
}
