#include <stdio.h>

int main()
{
  int n;
  scanf("%d", &n);
  int ax, ay, bx, by, cx, cy;
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);
#ifdef DEBUG
    printf("%d %d %d %d %d %d\n", ax, ay, bx, by, cx, cy);
#endif
    int ab = (ax - bx) * (ax -bx) + (ay - by) * (ay -by);
    int ac = (ax - cx) * (ax -cx) + (ay - cy) * (ay -cy);
    int bc = (cx - bx) * (cx -bx) + (cy - by) * (cy -by);
#ifdef DEBUG
    printf("%d %d %d\n", ab, ac, bc);
#endif
    if (ab == ac || ac == bc || ab == bc)
      printf("isosceles\n");
    else if (ab == ac + bc || ac == ab + bc || bc == ab + ac)
      printf("right\n");
    else if (ab < ac + bc && ac < ab + bc && bc < ab + ac)
      printf("acute\n");
    else
      printf("obtuse\n");

  }
  return 0;
}
