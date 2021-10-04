#include<stdio.h>
int main()
{
  int i,k=0;
  scanf("%d",&i);
  if (i<=0)
    k=-100;
  else {
    if (i%3==0)
      k=k+3;
    if (i%5==0)
      k=k+5;
    if (i>=100&&i<=200)
      k=k+50;
    if (i<100||i>200)
      k=k-50;
  }
  printf("%d",k);
  return 0;
}
