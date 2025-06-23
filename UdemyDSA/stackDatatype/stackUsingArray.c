#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack
{
  int size;
  int top;
  int *data;
} stack;

stack *createStack(int sz)
{
  stack *tmp = malloc(sizeof(stack));
  tmp->size = sz;
  tmp->top = -1;
  tmp->data = malloc(sizeof(int) * sz);

  return tmp;
}

void displayStack(stack *st)
{
  printf("The Stack:\n");
  for (int i = 0; i <= st->top; i++)
    printf("%d ", st->data[i]);
  printf("\n");
}

bool isStackFull(stack *st)
{
  return (st->top + 1 == st->size) ? true : false;
}

bool isStackEmpty(stack *st)
{
  return (st->top == -1) ? true : false;
}

bool push(stack *st, int val)
{
  if (!isStackFull(st))
  {
    st->top++;
    st->data[st->top] = val;
    return true;
  }
  else
  {
    printf("Stack Overflow!\n");
    return false;
  }
}

int pop(stack *const st)
{
  return isStackEmpty(st) ? -1 : st->data[st->top--];
}

int peek(const stack *const st, int index)
{
  return st->top - index + 1 >= 0 ? st->data[st->top - index + 1] : -1;
}

int stackTop(const stack *const st)
{
  return st->top >= 0 ? st->data[st->top] : -1;
}

bool freeStack(stack *st)
{
  free(st->data);
  free(st);

  return true;
}

int main()
{

  stack *st = createStack(5);

  printf("IsEmpty : %d\n", isStackEmpty(st));
  push(st, 1);
  displayStack(st);
  printf("IsEmpty : %d\n", isStackEmpty(st));
  push(st, 2);
  push(st, 3);
  push(st, 4);
  push(st, 5);
  push(st, 6);

  printf("IsFull : %d\n", isStackFull(st));
  displayStack(st);
  pop(st);
  displayStack(st);

  printf("Peeked: %d\n", peek(st, 3));
  printf("Top of Stack: %d\n", stackTop(st));
  freeStack(st);

  return 0;
}
