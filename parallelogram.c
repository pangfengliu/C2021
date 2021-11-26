#include <stdio.h>
 
int main()
{
  int ax, ay, bx, by, cx, cy;
  scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);
#ifdef DEBUG
  printf("%d%d%d%d%d%d\n", ax, ay, bx, by, cx, cy);
#endif
  printf("%d\n%d\n", bx + cx - ax, by + cy - ay);
  printf("%d\n%d\n", ax + cx - bx, ay + cy - by);
  printf("%d\n%d\n", ax + bx - cx, ay + by - cy);
  return 0;
}
