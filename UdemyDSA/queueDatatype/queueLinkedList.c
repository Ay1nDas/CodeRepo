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
  return -1;
}

void displayQueue(Queue *queue)
{
  printf("The Queue of size %d is:\n", queue->size);

  for (Node *ptr = queue->front; ptr != NULL; ptr = ptr->next)
    printf("%d ", ptr->data);

  printf("\n");
}

int main()
{
  Queue *queue = createQueue();
  printf("Is Empty? : %s\n", isEmpty(queue) ? "YES" : "NO");
  enQueue(queue, 1);
  enQueue(queue, 2);
  enQueue(queue, 3);
  enQueue(queue, 4);
  enQueue(queue, 5);
  displayQueue(queue);

  printf("deQueued: \n");
  while (!isEmpty(queue))
    printf("%d ", deQueue(queue));
  printf("\n");

  enQueue(queue, 1);
  enQueue(queue, 2);
  enQueue(queue, 10);
  displayQueue(queue);

  return 0;
}