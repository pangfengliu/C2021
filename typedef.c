#include <stdio.h>

#define ROW 2
#define COL 3

typedef int matrix[ROW][COL];

void print(void *ptr)
{
  matrix *mptr = (matrix *)ptr;
  for (int i = 0; i< ROW; i++)
    for (int j = 0; j < COL; j++)
      printf("%d\n", (*mptr) [i][j]);
}

int main()
{
  matrix m[] = {{{0, 1, 2}, {3, 4, 5}},
		{{1, 2, 3}, {4, 5, 6}}};
  print(&(m[0][1][1]) + 1);
  print(m + 1);
  return 0;
}
