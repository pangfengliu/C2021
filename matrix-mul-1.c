#include <stdio.h>

#include "multiply.h"

void multiplyMatrix(void ** arrayA, void ** arrayB, void ** arrayC)
{
  for (A **aptr = (A **)arrayA; *aptr != NULL; aptr++) {
    for (int r = 0; r < ROW; r++)
      for (int c = 0; c < COL; c++)
	printf("%d%c", (**aptr)[r][c], c == COL - 1? '\n' : ' ');
  }
}
