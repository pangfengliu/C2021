#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "bidding.h"
 
Bid findMaxBid(ItemMinPrice *ptr, Bid bidSeq[], int m)
{
  Bid maxBid;
  int maxBidPrice = INT_MIN;
  maxBid.bidPrice = INT_MIN;
  for (int i = 0; i < m; i++)
    if (bidSeq[i].itemID == ptr->itemID && 
	bidSeq[i].bidPrice >= ptr->minPrice && 
	bidSeq[i].bidPrice > maxBidPrice) {
      maxBidPrice = maxBid.bidPrice = bidSeq[i].bidPrice;
      maxBid.bidderID = bidSeq[i].bidderID;
      maxBid.itemID = ptr->itemID;
    }
  return maxBid;
}
 
bool wrongOrder(Bid a, Bid b)
{
  return (a.bidderID > b.bidderID || 
	  (a.bidderID == b.bidderID && a.itemID > b.itemID));
}
 
 
#define MAXITEM 1000
 
typedef struct transSet {
  Bid trans[MAXITEM];
  int num;
} TransSet;
 
void sortTransSet(TransSet *transSet) 
{
  Bid *trans = transSet->trans;
  for (int i = transSet->num - 2; i >= 0; i--)
    for (int j = 0; j <= i; j++)
      if (wrongOrder(trans[j], trans[j + 1])) {
	Bid temp = trans[j];
	trans[j] = trans[j + 1];
	trans[j + 1] = temp;
      }
}
 
void printTransSet(TransSet *transSet)
{
  Bid *ptr = transSet->trans;  
  for (int i = 0; i < transSet->num; i++, ptr++)
    printf("Bidder %d gets item %d with %d dollars\n", 
	   ptr->bidderID, ptr->itemID, ptr->bidPrice);
}
 
 
void addTransSet(TransSet *set, Bid bid)
{
  set->trans[set->num] = bid;
  set->num++;
}
 
void bidding(Bid bidSeq[], int m, ItemMinPrice minPriceSeq[], int n)
{
  TransSet transSet;
  transSet.num = 0;
 
  ItemMinPrice *ptr = minPriceSeq;
  for (int i = 0; i < n; i++, ptr++) {
    Bid maxBid = findMaxBid(ptr, bidSeq, m);
    if (maxBid.bidPrice != INT_MIN) {
      addTransSet(&transSet, maxBid);
    }
  }
  sortTransSet(&transSet);
  printTransSet(&transSet);
}
