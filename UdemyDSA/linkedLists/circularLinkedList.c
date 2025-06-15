#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *createCNode(int n)
{
  Node *node = malloc(sizeof(Node));
  node->data = n;
  node->next = node;

  return node;
}

bool displayCNode(Node *const head)
{
  Node *node = head;
  printf("Displaying Nodes: \n");
  do
  {
    printf("%d ", node->data);
    node = node->next;
  } while (node != head);
  printf("\n");

  return true;
}

Node *findNode(Node *head, int val)
{
  Node *node = head;
  do
  {
    if (node->data == val)
      return node;
    node = node->next;
  } while (node != head);

  return NULL;
}

bool appendCNode(Node *node, int val)
{
  Node *new_node = malloc(sizeof(Node));
  if (!new_node)
    return false;

  new_node->data = val;
  new_node->next = node->next;
  node->next = new_node;

  return true;
}

int delCNode(Node *head, Node *del)
{
  Node *node = head;
  int delData = -1;
  if (del == head)
    return delData;
  do
  {
    if (del == node->next)
    {
      node->next = del->next;
      delData = del->data;
      free(del);
      break;
    }
    node = node->next;
  } while (node->next != head);

  return delData;
}

bool freeCNode(Node *head)
{
  Node *node = head;
  do
  {
    Node *nxt = node->next;
    free(node);
    node = nxt;
  } while (node != head);
  return true;
}

int main()
{
  Node *head = createCNode(0);
  appendCNode(head, 4);
  appendCNode(head, 3);
  appendCNode(head, 2);
  appendCNode(head, 1);
  displayCNode(head);

  delCNode(head, head->next->next);
  displayCNode(head);

  Node *node = findNode(head, 4);
  if (node)
    printf("found: %d\n", node->data);

  freeCNode(head);
  return 0;
}
