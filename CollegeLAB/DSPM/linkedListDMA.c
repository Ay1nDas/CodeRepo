#include <stdio.h>
#include <stdlib.h>

struct node
{
  int val;
  struct node *next;
};

int main()
{
  struct node *firstNode = malloc(sizeof(struct node));
  firstNode->val = 10;

  struct node *secondNode = malloc(sizeof(struct node));
  secondNode->val = 20;

  struct node *thirdNode = malloc(sizeof(struct node));
  thirdNode->val = 30;

  firstNode->next = secondNode;
  secondNode->next = thirdNode;
  thirdNode->next = NULL;

  struct node *it = firstNode;
  while (it != NULL)
  {
    printf("%d \n", it->val);
    it = it->next;
  }

  return 0;
}