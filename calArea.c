#include <stdio.h>
#include <assert.h>
#include "calArea.h"

typedef struct point {
  NODE *ptr;
  int distance;
} Point;

Point goDown(Point *up)
{
  Point down;
  assert(up->ptr != NULL);
  NODE *this = up->ptr;
  down.distance = up->distance;
  while (this->downPtr != NULL) {
    this = this->downPtr;
    down.distance++;
  }
  down.ptr = this;
  return down;
}

void printPoint(Point point)
{
  printf("distance %d\n", point.distance);
}

int computeArea(Point up, Point down)
{
  #ifdef DEBUG
  printPoint(up);
  printPoint(down);
  #endif
  if (up.distance == down.distance)
    return 0;

  assert((up.ptr)->rightPtr != NULL &&
	 (down.ptr)->rightPtr != NULL);
  Point upRight = {(up.ptr)->rightPtr, up.distance};
  Point downRight = {(down.ptr)->rightPtr, down.distance};

  return ((down.distance - up.distance) +
	  computeArea(goDown(&upRight), goDown(&downRight)));
}

int calArea(NODE* head)
{
  Point up = {head, 0};
  Point down = goDown(&up);

  return computeArea(up, down);
}
