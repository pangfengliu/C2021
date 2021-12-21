#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define SLEN 1000000

typedef struct r
{
  bool valid;
  int index;
  int value;
} Result;

bool opr(char op)
{
  return (op == '+' || op == '-' || op == '*' || op == '/');
}

int comp(char op, int opd1, int opd2)
{
  switch (op) {
  case '+':
    return opd1 + opd2;
  case '-':
    return opd1 - opd2;
  case '*':
    return opd1 * opd2;
  case '/':
    return opd1 / opd2;
  }
  exit(-1);
}

Result getNum(char *string, int index)
{
  Result invalid = {false, 0, 0};
  int sum = string[index] - '0';
  index++;
  while (isdigit(string[index])) {
    sum = sum * 10 + (string[index] - '0');
    index++;
  }
  if (sum == 0)
    return invalid;
  else {
    Result num = {true, index, sum};
    return num;
  }
}

Result expression(char *string, int index)
{
  Result invalid = {false, 0, 0};
  if (string[index] != '(')
    return invalid;
  index++;

  if (isdigit(string[index])) {
    Result number1 = getNum(string, index);
    if (!number1.valid)
      return invalid;
    index = number1.index;
    if (!opr(string[index]))
      return invalid;
    char op = string[index];
    index++;
    if (!isdigit(string[index]))
      return invalid;      
      
    Result number2 = getNum(string, index);
    if (!number2.valid)
      return invalid;
    index = number2.index;
    if (string[index] != ')')
      return invalid;
    Result valid = {true, index + 1, comp(op, number1.value, number2.value)};
    return valid;
  } else if (string[index] == '(') {
    Result left = expression(string, index);
    if (!left.valid)
      return invalid;
    index = left.index;
    if (!opr(string[index]))
      return invalid;
    char op = string[index];
    index++;
    Result right = expression(string, index);
    if (!right.valid)
      return invalid;
    index = right.index;
    if (string[index] != ')')
      return invalid;
    Result valid = {true, index + 1, comp(op, left.value, right.value)};
    return valid;
  } else
    return invalid;
}
int main()
{
  char string[SLEN + 1];
  while (scanf("%s", string) != EOF) {
    Result result = expression(string, 0);
    if (!result.valid || string[result.index] != '\0')
      printf("invalid\n");
    else
      printf("%d\n", result.value);
  }
  return 0;
}
