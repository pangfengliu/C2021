#include <stdio.h>
#include <stdbool.h>
#include "lock.h"        /* I realyy do not care which .h I have */
 
#ifndef SENSOR
#define SENSOR 3
#endif
#ifndef MAXLIGHTS
#define MAXLIGHTS 20
#endif
#ifndef MAXLOCKS
#define MAXLOCKS 100
#endif
 
 
typedef struct status {
  bool on[MAXLIGHTS];
  int numOn;
  int power;
  int unlocked;
} Status;
 
void printStatus(Status *status, int numLights)
{
  for (int light = 0; light < numLights; light++)
    printf("%d", status->on[light]);
  printf("\n%d\n%d\n", status->unlocked, status->power);
}
 
void search(Locks *locks, int index, Status *status, Status *best, int numLights)
{
  if (index == numLights) {
    status->unlocked = numUnlocked(locks, status->on, numLights);
    if (status->unlocked > best->unlocked || 
    (status->unlocked == best->unlocked && status->power < best->power))
      *best = *status;
    return;
  }
 
  status->on[index] = true;
  status->numOn++;
  status->power += (1 << index);
  search(locks, index + 1, status, best, numLights);
 
  status->on[index] = false;
  status->numOn--;
  status->power -= (1 << index);
  search(locks, index + 1, status, best, numLights);
 
}
 
 
int main() 
{
  int numLights, numLocks;
  scanf("%d%d", &numLights, &numLocks);
  int lockSeq[MAXLOCKS][SENSOR];
 
  for(int lock = 0; lock < numLocks; lock++) {
    for(int seq = 0; seq < SENSOR; seq++) {
      scanf("%d", &lockSeq[lock][seq]);
    }
  }
  Locks *locks = init(lockSeq, numLocks);
 
  Status allOff;
  allOff.numOn = 0;
  for (int light = 0; light < numLights; light++)
    allOff.on[light] = false;
  allOff.numOn = allOff.power = 0;
 
  Status best;
  best.unlocked = -1;
 
  search(locks, 0, &allOff, &best, numLights);
  printStatus(&best, numLights);
 
  return 0;
}
