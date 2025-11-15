#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int val;
  struct node *next;
} node;

node *head = NULL;

void push_back(int value)
{
  if (head == NULL)
  {
    head = malloc(sizeof(node));
    head->val = value;
    head->next = NULL;
  }
  else
  {
    node *it = head;
    while (it->next != NULL)
    {
      it = it->next;
    }

    it->next = malloc(sizeof(node));
    it->next->val = value;
    it->next->next = NULL;
  }
}

void push_front(int value)
{
  if (head == NULL)
  {
    head = malloc(sizeof(node));
    head->val = value;
    head->next = NULL;
  }
  else
  {
    node *newHead = malloc(sizeof(node));
    newHead->val = value;
    newHead->next = head;
    head = newHead;
  }
}

void push_at(int idx, int value)
{
  if (head == NULL)
  {
    head = malloc(sizeof(node));
    head->val = value;
    head->next = NULL;
  }
  else
  {
    node *it = head;
    for (int i = 0; i < idx - 1 && it->next != NULL; i++)
    {
      it = it->next;
    }

    node *inNode = malloc(sizeof(node));
    inNode->val = value;
    inNode->next = it->next;
    it->next = inNode;
  }
}

int pop_back()
{
  if (head == NULL)
  {
    return -1;
  }
  else if (head->next == NULL)
  {
    int retVal = head->val;
    free(head);
    head = NULL;

    return retVal;
  }
  else
  {
    node *it = head;
    while (it->next->next != NULL)
    {
      it = it->next;
    }

    int retVal = it->next->val;
    free(it->next);
    it->next = NULL;

    return retVal;
  }
}

int pop_front()
{
  if (head == NULL)
  {
    return -1;
  }
  else
  {
    node *newHead = head->next;
    int retVal = head->val;

    free(head);
    head = newHead;

    return retVal;
  }
}

int pop_at(int idx)
{
  if (head == NULL)
  {
    return -1;
  }
  else if (head->next == NULL)
  {
    int retVal = head->val;
    free(head);
    head = NULL;

    return retVal;
  }
  else
  {
    node *it = head;
    for (int i = 0; i < idx - 1 && it->next != NULL; i++)
    {
      it = it->next;
    }

    if (it->next == NULL)
    {
      return -1;
    }
    else
    {
      node *nextNode = it->next->next;
      int retVal = it->next->val;

      free(it->next);
      it->next = nextNode;

      return retVal;
    }
  }
}

void printLinkedList()
{
  for (node *it = head; it != NULL; it = it->next)
  {
    printf("%d -> ", it->val);
  }
  printf("NULL\n");
}

int main()
{
  push_back(10);
  push_back(20);
  push_back(30);
  printLinkedList();

  push_at(1, 15);
  push_front(5);
  printLinkedList();

  printf("%d \n", pop_back());
  printf("%d \n", pop_front());
  printf("%d \n", pop_at(1));
  printLinkedList();

  return 0;
}