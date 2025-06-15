#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *createNode(const int val)
{
  Node *tmp_node = malloc(sizeof(Node));
  tmp_node->data = val;
  tmp_node->next = NULL;

  return tmp_node;
}

bool appendNode(Node *node, int val)
{
  Node *tmp_node = malloc(sizeof(Node));
  if (!tmp_node)
    return false;
  tmp_node->data = val;
  tmp_node->next = node->next;
  node->next = tmp_node;
  return true;
}

bool popNode(Node *node, int index)
{
  if (index == 0)
  {
    printf("Error: Can't pop head using popNode().");
    return false;
  }

  for (int i = 0; node->next && i < index - 1; i++)
    node = node->next;

  if (node->next)
  {
    Node *tmp = node->next;
    node->next = node->next->next;
    free(tmp);
    return true;
  }
  else
  {
    return false;
  }
}

bool appendArrNode(Node *node, int arr[], int arrSize)
{
  Node *tmp_head = malloc(sizeof(Node));
  if (!tmp_head)
    return false;
  tmp_head->data = arr[0];
  tmp_head->next = NULL;

  Node *curr_node = tmp_head;
  for (int i = 1; i < arrSize; i++)
  {
    // printf("i : %d\n", i);
    Node *tmp_node = malloc(sizeof(Node));
    if (!tmp_node)
      return false;
    tmp_node->data = arr[i];
    tmp_node->next = NULL;
    curr_node->next = tmp_node;
    curr_node = tmp_node;
    // printf("curr: %d\n", curr_node->data);
  }

  curr_node->next = node->next;
  node->next = tmp_head;
  return true;
}

void displayList(Node *node)
{
  printf("Displaying Nodes:\n");
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

Node *findNode(Node *node, int val)
{
  while (node)
  {
    if (node->data == val)
      break;

    node = node->next;
  }

  return node;
}

Node *concatenate(Node *node1, Node *node2)
{
  Node *headNode = node1;
  while (node1->next)
    node1 = node1->next;

  node1->next = node2;

  return headNode;
}

Node *reverseList(Node *node)
{

  Node *pre_node = NULL;
  Node *nxt_node = NULL;

  while (node)
  {
    nxt_node = node->next;
    node->next = pre_node;

    pre_node = node;
    node = nxt_node;
  }

  return pre_node;
}

bool freeList(Node *node)
{
  if (node->next == NULL)
  {
    free(node);
    return true;
  }

  return (freeList(node->next) ? true : false);
}

Node *sortList(Node *node)
{
  Node *head_node = node;
  Node *n = node->next;
  head_node->next = NULL;

  while (n != NULL)
  {
    // printf("n: %d\n", n->data);
    if (head_node->data > n->data)
    {
      Node *nxt = n->next;
      n->next = head_node;
      head_node = n;
      n = nxt;
      continue;
    }

    Node *sorted_node = head_node;
    bool isSorted = false;

    while (sorted_node->next)
    {
      if (sorted_node->next->data >= n->data)
      {
        Node *nxt = n->next;
        n->next = sorted_node->next;
        sorted_node->next = n;
        n = nxt;
        isSorted = true;
        break;
      }
      sorted_node = sorted_node->next;
    }

    if (!isSorted)
    {
      Node *nxt = n->next;
      sorted_node->next = n;
      n->next = NULL;
      n = nxt;
    }
  }
  return head_node;
}

bool isLoop(Node *node)
{
  Node *f, *s;
  f = s = node;
  do
  {
    f = f->next;
    s = s->next;
    if (s->next)
      s = s->next;

    if (f == s)
      return true;

  } while (f && s);

  return false;
}

int main()
{

  Node *head = createNode(0);
  appendNode(head, 1);
  displayList(head);

  int arr[] = {3, 4, 5};
  appendArrNode(head->next, arr, sizeof(arr) / sizeof(arr[0]));

  Node *ptr = findNode(head, 1);
  if (ptr)
    appendNode(ptr, 2);
  displayList(head);

  popNode(head, 5);
  displayList(head);

  popNode(head, 0);
  displayList(head);

  popNode(head, 2);
  displayList(head);

  Node *rev_head = reverseList(head);
  displayList(rev_head);

  Node *head2 = createNode(69);
  appendNode(head2, 420);
  displayList(head2);

  Node *rev2 = reverseList(head2);
  displayList(rev2);

  Node *con_head = concatenate(rev_head, rev2);
  displayList(con_head);

  freeList(con_head);

  Node *new_node = createNode(5);
  int arr2[] = {9, 1, 6, 3};
  appendArrNode(new_node, arr2, sizeof(arr2) / sizeof(arr2[0]));
  displayList(new_node);

  Node *sorted = sortList(new_node);
  displayList(sorted);

  freeList(sorted);

  return 0;
}
