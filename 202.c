#include <stdio.h>

int main()
{
  int a, b, c, d, e, f, g;
  scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
  int newb = (a < 0? a * c - b : a * c + b);
  int newf = (e < 0? e * g - f : e * g + f);
#ifdef DEBUG
  printf("%d %d\n", newb, newf);
#endif
  int divisor, dividend;
  
  switch (d) {
  case 0:
    divisor = c * g;
    dividend = newb * g + newf * c;
    break;
  case 1:
    divisor = c * g;
    dividend = newb * g - newf * c;
    break;
  case 2:
    divisor = c * g;
    dividend = newb * newf;
    break;
  case 3:
    divisor = c * newf;
    dividend = newb * g;
    if (divisor < 0) {
      divisor = -divisor;
      dividend = -dividend;
    }
    break;
  }
  
#ifdef DEBUG
  printf("%d %d\n", dividend, divisor);
#endif
  
  int x = (dividend > 0? dividend : -dividend);
  int y = (divisor> 0? divisor : -divisor);

  while (x % y != 0) {
    int reminder = x % y;
    x = y;
    y = reminder;
  }
  int factor = y;
  dividend /= factor;
  divisor /= factor;

  int integer = dividend / divisor;
  dividend = dividend % divisor;

#ifdef DEBUG
  printf("%d %d\n", dividend, divisor);
#endif

  if (dividend < 0)
    dividend = -dividend;
  
  if (dividend == 0)
    divisor = 1;

  printf("%d\n%d\n%d\n", integer, dividend, divisor);
  
  return 0;
}
