#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Heap
{
  int *data;
  int size;
  int filled;

} Heap;

Heap *createHeap(int sz)
{
  Heap *tmp = malloc(sizeof(Heap));
  if (tmp)
  {
    tmp->data = malloc(sizeof(int) * sz);
    tmp->filled = 0;
    tmp->size = tmp->data ? sz : 0;
  }

  return tmp;
}

bool isHeapFull(Heap *heap)
{
  return heap->size == heap->filled ? true : false;
}

bool isHeapEmpty(Heap *heap)
{
  return heap->filled ? false : true;
}

bool insert(Heap *heap, int value)
{
  if (isHeapFull(heap))
    return false;

  int ins_posn = heap->filled;
  while (ins_posn > 0 && heap->data[ins_posn / 2] < value)
  {
    heap->data[ins_posn] = heap->data[ins_posn / 2];
    ins_posn /= 2;
  }
  heap->data[ins_posn] = value;
  heap->filled++;

  return true;
}

int delete(Heap *heap)
{
  if (isHeapEmpty(heap))
    return -1;

  int retVal = heap->data[0];
  heap->filled--;

  heap->data[0] = heap->data[heap->filled];
  int change_idx = 0;
  int child_idx = change_idx * 2 + 1;

  int lChild = child_idx < heap->filled ? heap->data[child_idx] : -1;
  int rChild = child_idx + 1 < heap->filled ? heap->data[child_idx + 1] : -1;

  if (lChild < rChild)
    child_idx++;

  while (child_idx < heap->filled && heap->data[child_idx] > heap->data[change_idx])
  {
    int tmp = heap->data[change_idx];

    heap->data[change_idx] = heap->data[child_idx];
    heap->data[child_idx] = tmp;

    change_idx = child_idx;
    child_idx = change_idx * 2 + 1;

    lChild = child_idx < heap->filled ? heap->data[child_idx] : -1;
    rChild = child_idx + 1 < heap->filled ? heap->data[child_idx + 1] : -1;

    if (lChild < rChild)
      child_idx++;
  }

  return retVal;
}

void heapSort(Heap *heap)
{
  int original_cnt = heap->filled;
  while (!isHeapEmpty(heap))
  {
    int removed = delete(heap);
    heap->data[heap->filled] = removed;
  }

  heap->filled = original_cnt;
}

void display(Heap *heap)
{
  printf("Current Heap is:%s\n", heap->filled ? " " : " Empty");
  for (int i = 0; i < heap->filled; i++)
    printf("%d ", heap->data[i]);

  printf("\n");
}

int main()
{
  Heap *h1 = createHeap(10);
  insert(h1, 40);
  insert(h1, 35);
  insert(h1, 30);
  insert(h1, 15);
  insert(h1, 20);
  insert(h1, 25);
  insert(h1, 5);
  display(h1);

  delete(h1);
  display(h1);

  heapSort(h1);
  display(h1);

  return 0;
}
