#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct doublyLinkedNode
{
  int data;
  struct doublyLinkedNode *prev;
  struct doublyLinkedNode *post;
} dNode;

dNode *createDList(int val)
{
  dNode *head = malloc(sizeof(dNode));
  head->data = val;
  head->prev = NULL;
  head->post = NULL;

  return head;
}

bool insertNode(dNode *node, int val)
{
  dNode *new = malloc(sizeof(dNode));
  new->data = val;
  new->post = node->post;
  new->prev = node;
  if (node->post)
    node->post->prev = new;
  node->post = new;

  return true;
}

int deleteNode(dNode *delNode)
{
  if (delNode && delNode->prev)
  {
    delNode->prev->post = delNode->post;
    delNode->post->prev = delNode->prev;

    int val = delNode->data;
    free(delNode);

    return val;
  }
  else
  {
    return -1;
  }
}

void displayList(dNode *node)
{
  printf("The list: \n");
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->post;
  }
  printf("\n");
}

int main()
{
  dNode *head = createDList(0);
  insertNode(head, 4);
  insertNode(head, 3);
  insertNode(head, 2);
  insertNode(head, 1);
  displayList(head);

  deleteNode(head->post);
  displayList(head);
  return 0;
}