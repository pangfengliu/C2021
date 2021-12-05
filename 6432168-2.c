#include <stdio.h>
 
#define ONETOMANY 1
#define MANYTOONE 0
 
int char2byte(char c)
{
  switch (c) {
  case 'C':
    return 1;
  case 'S':
    return 2;
  case 'L':
    return 4;
  default:
    return 0;
  }
}
 
void manytoone(char *format, unsigned int thirtytwo,
	       unsigned short int sixteen, char *string)
{
#ifdef DEBUG
  printf("%s %u %hu %s\n", format, thirtytwo, sixteen, string);
#endif
  int charCount = 0;
  unsigned long long sixtyfour = 0;
  for (int i = 0; i < 4; i++) {
    switch (char2byte(format[i])) {
    case 1:            /* C */
      sixtyfour |= string[charCount++];
      break;
    case 2:            /* S */
      sixtyfour |= sixteen;
      break;
    case 4:            /* L */
      sixtyfour |= thirtytwo;
      break;
    }
    if (i < 3)
      sixtyfour <<= ((char2byte(format[i + 1]) * 8));
  }
  printf("%llu\n", sixtyfour);
}
 
void onetomany(char *format, unsigned long long sixtyfour)
{
  unsigned int thirtytwo;
  unsigned short int sixteen;
  char string[4] = {0};
  int charCount = 1;
 
  for (int i = 3; i >= 0; i--) {
    int numbyte = char2byte(format[i]);
    unsigned long long mask = ((unsigned long long)1 << (numbyte * 8)) - 1;
#ifdef DEBUG
    printf("%llx %llx %d\n", sixtyfour, mask, numbyte);
#endif
    switch (numbyte) {
    case 1:            /* C */
      string[charCount--] = sixtyfour & mask;
      break;
    case 2:            /* S */
      sixteen = sixtyfour & mask;
      break;
    case 4:            /* L */
      thirtytwo = sixtyfour & mask;
      break;
    }
    sixtyfour >>= (numbyte * 8);
  }
  printf("%u %hu %s\n", thirtytwo, sixteen, string); 
}
 
int main()
{
  int type;
  scanf("%d", &type);
  unsigned long long int sixtyfour;
  unsigned int thirtytwo;
  unsigned short int sixteen;
  char string[4], format[20];
  switch (type) {
  case MANYTOONE:
    while (scanf("%s%u%hu%s", format, &thirtytwo, &sixteen, string) != EOF)
      manytoone(format, thirtytwo, sixteen, string);
    break;
  case ONETOMANY:
    while (scanf("%s%llu", format, &sixtyfour) != EOF)
      onetomany(format, sixtyfour);
    break;
  }
  return 0;
}
