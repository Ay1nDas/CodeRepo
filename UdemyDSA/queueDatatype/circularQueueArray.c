#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
  int size;
  int first;
  int rear;
  int *data;
} Queue;

Queue *createQueue(int sz)
{
  Queue *new = malloc(sizeof(Queue));
  new->data = calloc(sz, sizeof(int));
  new->first = new->rear = 0;
  new->size = sz;

  return new->data ? new : NULL;
}

bool isFull(Queue *queue)
{
  if ((queue->rear + 1) % queue->size == queue->first)
    return true;
  else
    return false;
}

bool isEmpty(Queue *queue)
{
  if (queue->first == queue->rear)
    return true;
  else
    return false;
}

bool enQueue(Queue *queue, int val)
{
  if (isFull(queue))
    return false;

  queue->rear = (queue->rear + 1) % queue->size;
  queue->data[queue->rear] = val;
  return true;
}

int deQueue(Queue *queue)
{
  if (isEmpty(queue))
    return -1;

  queue->first = (queue->first + 1) % queue->size;
  int deVal = queue->data[queue->first];
  return deVal;
}

void displayQueue(Queue *queue)
{
  for (int i = queue->first; i != queue->rear; i = (i + 1) % queue->size)
    printf("%d ", queue->data[(i + 1) % queue->size]);
  printf("\n");
}

int main()
{
  Queue *queue = createQueue(5);
  enQueue(queue, 1);
  enQueue(queue, 2);
  enQueue(queue, 3);
  enQueue(queue, 4);
  displayQueue(queue);
  printf("deQueued: %d\n", deQueue(queue));
  printf("deQueued: %d\n", deQueue(queue));
  enQueue(queue, 5);
  enQueue(queue, 6);
  displayQueue(queue);

  return 0;
}