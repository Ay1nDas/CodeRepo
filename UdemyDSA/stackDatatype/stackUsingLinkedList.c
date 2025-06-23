#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
  int val;
  struct Node *next;
} Node;

typedef struct Stack
{
  int size;
  Node *top;
} Stack;

Stack *createStack()
{
  Stack *tmp = malloc(sizeof(Stack));
  tmp->size = 0;
  tmp->top = NULL;
}

void displayStack(Stack *st)
{
  printf("The Stack has '%d' Values as: \n", st->size);
  Node *node = st->top;
  while (node)
  {
    printf("%d ", node->val);
    node = node->next;
  }
  printf("\n");
}

bool isStackEmpty(Stack *st)
{
  return st->size ? false : true;
}

bool push(Stack *st, int data)
{
  Node *tmp = malloc(sizeof(Node));
  if (!tmp)
    return false;

  tmp->val = data;
  tmp->next = st->top;
  st->top = tmp;
  st->size++;
}

int pop(Stack *st)
{
  int topVal = -1;
  if (st->top)
  {
    Node *topNode = st->top;
    st->top = topNode->next;
    st->size--;
    topVal = topNode->val;
    free(topNode);
  }

  return topVal;
}

int peek(Stack *st, int index)
{
  if (index > st->size)
    return -1;

  Node *peekedNode = st->top;
  while (--index)
    peekedNode = peekedNode->next;

  return peekedNode->val;
}

int stackTop(Stack *st)
{
  return st->top ? st->top->val : -1;
}

bool freeStack(Stack *st)
{
  while (st->top)
  {
    Node *tmp = st->top;
    st->top = tmp->next;
    free(tmp);
  }

  free(st);
}

int main()
{
  Stack *st = createStack();
  displayStack(st);

  push(st, 5);
  push(st, 4);
  push(st, 3);
  push(st, 2);
  push(st, 1);
  displayStack(st);

  printf("Popped: %d\n", pop(st));
  printf("Popped: %d\n", pop(st));
  displayStack(st);
  printf("Top of Stack: %d\n", stackTop(st));
  printf("Peeked: %d\n", peek(st, 2));

  freeStack(st);
  return 0;
}
