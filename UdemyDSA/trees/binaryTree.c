#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// typedef struct Branch
// {
//   int data;
//   struct Node *next;
// } Branch;

typedef struct TreeNode
{
  int value;
  struct TreeNode *left;
  struct TreeNode *right;

} TreeNode;

typedef struct Node
{
  TreeNode *data;
  struct Node *next;
} Node;

typedef struct Queue
{
  int size;
  Node *front;
  Node *rear;
} Queue;

Queue *createQueue()
{
  Queue *new = malloc(sizeof(Queue));
  new->size = 0;
  new->front = NULL;
  new->rear = NULL;
}

bool isEmpty(Queue *queue)
{
  return queue->size == 0 ? true : false;
}

bool enQueue(Queue *queue, TreeNode *node)
{
  Node *new_node = malloc(sizeof(Node));
  if (new_node == NULL)
  {
    printf("Stack Full! \n");
    return false;
  }

  new_node->data = node;
  new_node->next = NULL;

  if (isEmpty(queue))
    queue->front = new_node;
  else
    queue->rear->next = new_node;

  queue->rear = new_node;
  queue->size++;

  return true;
}

TreeNode *deQueue(Queue *queue)
{
  if (isEmpty(queue))
    return NULL;

  Node *first = queue->front;
  queue->front = queue->front->next;
  queue->size--;

  if (isEmpty(queue))
    queue->rear = queue->front = NULL;

  TreeNode *retVal = first->data;
  free(first);

  return retVal;
}

TreeNode *createTree(int values[], int valueSize)
{
  TreeNode *root = malloc(sizeof(TreeNode));
  root->value = values[0];
  root->left = NULL;
  root->right = NULL;

  Queue *treeQueue = createQueue();
  enQueue(treeQueue, root);
  int idx = 1;

  while (!isEmpty(treeQueue) && idx < valueSize)
  {
    TreeNode *currNode = deQueue(treeQueue);
    if (!currNode)
    {
      idx += 2;
      continue;
    }

    if (values[idx] != -1 && idx < valueSize)
    {
      // printf("%d ", values[idx]);
      TreeNode *newNode = malloc(sizeof(TreeNode));
      newNode->value = values[idx];
      newNode->left = NULL;
      newNode->right = NULL;

      currNode->left = newNode;
      enQueue(treeQueue, newNode);
    }
    else
    {
      enQueue(treeQueue, NULL);
    }
    idx++;

    if (values[idx] != -1 && idx < valueSize)
    {
      // printf("%d ", values[idx]);
      TreeNode *newNode = malloc(sizeof(TreeNode));
      newNode->value = values[idx];
      newNode->left = NULL;
      newNode->right = NULL;

      currNode->right = newNode;
      enQueue(treeQueue, newNode);
    }
    else
    {
      enQueue(treeQueue, NULL);
    }
    idx++;
  }
  // printf("\n%d %d\n", idx, valueSize);
  return root;
}

void displayTree(TreeNode *node)
{
  if (node == NULL)
  {
    printf("-1 ");
    return;
  }

  printf("%d ", node->value);
  displayTree(node->left);
  displayTree(node->right);
}

int main()
{
  int tree[] = {1, 2, 2, -1, 3, 1, -1, -1, -1, 4};
  TreeNode *root = createTree(tree, sizeof(tree) / sizeof(tree[0]));

  printf("\n");
  displayTree(root);
  printf("\n");

  return 0;
}