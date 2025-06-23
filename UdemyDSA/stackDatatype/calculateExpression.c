#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Ops
{
  int value;
  char op;
} Ops;

typedef struct Stack
{
  int size;
  int top;
  Ops *data;
} Stack;

Stack *createStack(int sz)
{
  Stack *tmp = malloc(sizeof(Stack));
  tmp->size = sz;
  tmp->top = -1;
  tmp->data = malloc(sizeof(Ops) * sz);

  return tmp;
}

void displayStack(Stack *st)
{
  printf("The Stack:\n");
  for (int i = 0; i <= st->top; i++)
    printf("%d%c ", st->data[i].value, st->data[i].op);
  printf("\n");
}

bool isStackFull(Stack *st)
{
  return (st->top + 1 == st->size) ? true : false;
}

bool isStackEmpty(Stack *st)
{
  return (st->top == -1) ? true : false;
}

bool push(Stack *st, Ops operations)
{
  if (!isStackFull(st))
  {
    st->top++;
    st->data[st->top] = operations;
    return true;
  }
  else
  {
    printf("Stack Overflow!\n");
    return false;
  }
}

Ops pop(Stack *const st)
{
  Ops nullVal;
  nullVal.op = ' ';
  nullVal.value = -1;

  return isStackEmpty(st) ? nullVal : st->data[st->top--];
}

Ops stackTop(const Stack *const st)
{
  Ops nullVal;
  nullVal.op = ' ';
  nullVal.value = -1;

  return st->top >= 0 ? st->data[st->top] : nullVal;
}

int evaluate(char exp[], int size)
{
  Stack *expStack = createStack(10);
  Ops currOps = {0, '+'};

  for (int i = 0; i < size; i++)
  {
    if (exp[i] == ' ')
      continue;
    else if (exp[i] >= '0' && exp[i] <= '9')
    {
      currOps.value *= 10;
      currOps.value += exp[i] - '0';
    }
    else if (exp[i] == '(')
    {
      if (currOps.value != 0)
      {
        currOps.op = '*';
        push(expStack, currOps);
      }
      currOps.value = 0;
      currOps.op = '+';
      push(expStack, currOps);
      currOps.op = '_';
    }
    else if (exp[i] == ')')
    {
      // printf("Here1\n");
      // printf("Top: %d\n", stackTop(expStack).value);
      // displayStack(expStack);
      Ops topOp;

      do
      {
        topOp = pop(expStack);
        // printf("Exp is: %d%c\n", topOp.value, topOp.op);
      } while (topOp.value == 0 && topOp.op == '+');

      switch (topOp.op)
      {
      case '*':
        currOps.value *= topOp.value;
        break;
      case '/':
        currOps.value = topOp.value / currOps.value;
        break;
      case '+':
        currOps.value += topOp.value;
        break;
      case '-':
        currOps.value = topOp.value - currOps.value;
        break;
      }

      while (exp[++i] == ' ')
        continue;

      // printf("Exp: %c\n", exp[i]);

      if (exp[i] >= '0' && exp[i] <= '9')
      {
        currOps.op = '*';
        push(expStack, currOps);
        currOps.value = 0;
        currOps.op = '_';
      }
      i--;
    }
    else
    {
      // printf("%d ", exp[i]);
      currOps.op = exp[i];
      Ops topOp;

      switch (currOps.op)
      {
      case '*':
      case '/':
        topOp = stackTop(expStack);
        if (topOp.op == '*' || topOp.op == '/')
        {
          topOp = pop(expStack);
          if (topOp.op == '*')
            currOps.value *= topOp.value;
          else if (topOp.op == '/')
            currOps.value = topOp.value / currOps.value;
        }
        else if (topOp.value == 0 && topOp.op == '+')
        {
          pop(expStack);
        }

        push(expStack, currOps);
        break;

      case '+':
      case '-':
      case '\0':
        topOp = pop(expStack);

        switch (topOp.op)
        {
        case '*':
          currOps.value *= topOp.value;
          break;
        case '/':
          currOps.value = topOp.value / currOps.value;
          break;
        case '+':
          currOps.value += topOp.value;
          break;
        case '-':
          currOps.value = topOp.value - currOps.value;
          break;

        default:
          break;
        }

        push(expStack, currOps);
        break;

      default:
        break;
      }

      currOps.value = 0;
      currOps.op = '_';
    }
    // displayStack(expStack);
  }

  // displayStack(expStack);

  int value = pop(expStack).value;
  while (stackTop(expStack).value != -1)
  {
    Ops topOp = pop(expStack);

    switch (topOp.op)
    {
    case '*':
      value *= topOp.value;
      break;
    case '/':
      value = topOp.value / value;
      break;
    case '+':
      value += topOp.value;
      break;
    case '-':
      value = topOp.value - value;
      break;
    }
  }
  return value;
}

int main()
{
  char exp[] = "3 * (2 + 3*4)"; // Ans: 21;

  printf("Value of %s = %d\n", exp, evaluate(exp, sizeof(exp) / sizeof(exp[0])));
  // printf("%d\n", exp[sizeof(exp) / sizeof(exp[0]) - 1]);
  // evaluate(exp, sizeof(exp) / sizeof(exp[0]));
  return 0;
}