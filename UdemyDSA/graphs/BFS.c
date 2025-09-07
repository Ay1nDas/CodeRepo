#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
  int data;
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

bool isFull(Queue *queue)
{
  Node *new = malloc(sizeof(Node));
  bool isPossible = (new == NULL ? true : false);
  free(new);

  return isPossible;
}

bool enQueue(Queue *queue, int val)
{
  Node *new_node = malloc(sizeof(Node));
  if (new_node == NULL)
  {
    printf("Stack Full! \n");
    return false;
  }

  new_node->data = val;
  new_node->next = NULL;

  if (isEmpty(queue))
    queue->front = new_node;
  else
    queue->rear->next = new_node;

  queue->rear = new_node;
  queue->size++;

  return true;
}

int deQueue(Queue *queue)
{
  if (isEmpty(queue))
    return -1;

  Node *first = queue->front;
  queue->front = queue->front->next;
  queue->size--;

  if (isEmpty(queue))
    queue->rear = queue->front = NULL;

  int retVal = first->data;
  free(first);

  return retVal;
}

int *bfs(int **graph, int sz, int startNode)
{
  int *visitedNode = malloc((sz + 1) * sizeof(int));
  int *bfsValue = malloc((sz + 1) * sizeof(int));
  int bfsIdx = 0;

  bfsValue[bfsIdx++] = startNode;
  visitedNode[startNode] = 1;
  Queue *q = createQueue();
  enQueue(q, startNode);

  while (!isEmpty(q))
  {
    int node = deQueue(q);

    for (int vertex = 1; vertex <= sz; vertex++)
    {
      if (graph[node][vertex] == 1 && visitedNode[vertex] == 0)
      {
        visitedNode[vertex] = 1;
        bfsValue[bfsIdx++] = vertex;
        enQueue(q, vertex);
      }
    }
  }

  return bfsValue;
}

int main()
{
  int n, edgeSize;
  scanf("%d %d", &n, &edgeSize);

  int **graph = malloc((n + 1) * sizeof(int *));
  for (int i = 0; i < n + 1; i++)
    graph[i] = calloc(n + 1, sizeof(int));

  for (int i = 0; i < edgeSize; i++)
  {
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    graph[n1][n2] = 1;
    graph[n2][n1] = 1;
  }

  int *bfsVale = bfs(graph, n, 1);

  for (int i = 0; i < n; i++)
    printf("%d ", bfsVale[i]);
  printf("\n");

  return 0;
}