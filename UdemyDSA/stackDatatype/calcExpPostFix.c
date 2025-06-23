#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
  size_t size;
  int top;
  void *data;
} stack;

long long power(long long a, long long b)
{
  long long remainderMultiply = 1;
  while (b > 1)
  {
    if (b % 2 == 0)
    {
      a *= a;
      b /= 2;
    }
    else
    {
      remainderMultiply *= a;
      a *= a;
      b = (b - 1) / 2; // --b/=2?
    }
  }
  return remainderMultiply * a;
}

int outStackPre(char op)
{
  switch (op)
  {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 3;
  case '^':
    return 6;
  case '(':
    return 7;
  case ')':
    return 0;

  default:
    return -1;
  }
}

int inStackPre(char op)
{
  switch (op)
  {
  case '+':
  case '-':
    return 2;
  case '*':
  case '/':
    return 4;
  case '^':
    return 5;
  case '(':
    return 0;

  default:
    return -1;
  }
}

int stackTopNum(stack *st)
{
  return (st->top >= 0) ? ((int *)st->data)[st->top] : -1;
}

char stackTopOpr(stack *st)
{
  return (st->top >= 0) ? ((char *)st->data)[st->top] : '\0';
}

void pushNum(stack *st, int val)
{
  ((int *)st->data)[++st->top] = val;
}

int popNum(stack *st)
{
  return st->top >= 0 ? ((int *)st->data)[st->top--] : -1;
}

void pushOpr(stack *st, char val)
{
  ((char *)st->data)[++st->top] = val;
}

int popOpr(stack *st)
{
  return st->top >= 0 ? ((char *)st->data)[st->top--] : -1;
}

int operate(int num2, int num1, char operation)
{
  // printf("%d %c %d\n", num1, operation, num2);
  switch (operation)
  {
  case '+':
    return num1 + num2;
  case '-':
    return num1 - num2;
  case '*':
    return num1 * num2;
  case '/':
    return num1 / num2;
  case '^':
    return power(num1, num2);

  default:
    return 0;
  }
}

int main()
{
  // printf("%d\n", (int)pow(2, 3));

  char exp[1024];
  printf("Enter Your expression: ");
  fgets(exp, sizeof(exp), stdin);

  size_t expSize = strlen(exp);
  // printf("%ld\n", expSize);

  stack *numStack = malloc(sizeof(stack));
  numStack->size = expSize;
  numStack->top = -1;
  numStack->data = malloc(expSize * sizeof(int));

  stack *oprStack = malloc(sizeof(stack));
  oprStack->size = expSize;
  oprStack->top = -1;
  oprStack->data = malloc(expSize * sizeof(char));
  int latestNum = 0;

  for (int i = 0; i < expSize; i++)
  {
    printf("%d ", exp[i]);
    if (exp[i] == ' ')
      continue;

    if (exp[i] < '0' || exp[i] > '9')
    {
      while (inStackPre(stackTopOpr(oprStack)) > outStackPre(exp[i]))
      {
        char opr = popOpr(oprStack);
        if (latestNum == -1000)
          latestNum = popNum(numStack);

        latestNum = operate(latestNum, popNum(numStack), opr);
        // printf("Exp: %c, Val: %d\n", exp[i], latestNum);
      }
      if (inStackPre(stackTopOpr(oprStack)) == outStackPre(exp[i]))
        popOpr(oprStack);
      else
        pushOpr(oprStack, exp[i]);

      if (latestNum != -1000)
        pushNum(numStack, latestNum);
      latestNum = -1000;
    }
    else
    {

      if (latestNum == -1000)
        latestNum = 0;

      latestNum *= 10;
      latestNum += exp[i] - '0';
    }
  }
  printf("|\n");

  printf("Ans: %d\n", stackTopNum(numStack));

  return 0;
}