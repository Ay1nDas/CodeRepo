#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Creating an array and it's functions.

typedef struct Array
{
  int *value;
  size_t size;

} Array;

Array *createArr(int size)
{
  Array *arr = (Array *)malloc(sizeof(Array));
  if (arr == NULL)
  {
    printf("Array Failed!\n");
    return NULL;
  }

  arr->value = (int *)calloc(size, sizeof(int));

  arr->size = (arr->value) ? size : 0;
  return arr;
}

bool freeArr(Array **arr)
{
  free((*arr)->value);
  (*arr)->value = NULL;
  free(*arr);
  *arr = NULL;

  return true;
}

void displayArr(const Array *const arr)
{
  for (int i = 0; i < arr->size; i++)
  {
    printf("%d ", arr->value[i]);
  }
  printf("\n");
}

bool append(Array *const arr, int val)
{
  int *tmp = realloc(arr->value, (arr->size + 1) * sizeof(int));

  if (tmp == NULL)
  {
    printf("append Failed!\n");
    return false;
  }

  arr->value = tmp;
  arr->size++;
  arr->value[arr->size - 1] = val;

  return true;
}

bool push_back(Array *const arr, int val)
{
  return append(arr, val);
}

int pop_back(Array *arr)
{
  int popped = arr->value[arr->size];
  int *tmp = realloc(arr->value, (arr->size - 1) * sizeof(int));
  if (tmp == NULL)
  {
    printf("Pop Failed!\n");
    return -1;
  }
  else
  {
    arr->value = tmp;
    arr->size--;
    return popped;
  }
}

bool insert(Array *const arr, size_t index, int val)
{
  if (index > arr->size)
  {
    printf("Index out of bounds!\n");
    return false;
  }

  int *tmp = realloc(arr->value, (arr->size + 1) * sizeof(int));
  if (tmp == NULL)
  {
    printf("Inserting Failed!\n");
    return false;
  }

  arr->value = tmp;
  arr->size++;

  for (int i = arr->size - 1; i > index; i--)
  {
    arr->value[i] = arr->value[i - 1];
  }

  arr->value[index] = val;
  return true;
}

int delete(Array *const arr, size_t index)
{
  if (index >= arr->size)
  {
    printf("No element at index: %lu; Size of array: %lu\n", index, arr->size);
    return -1;
  }

  int deleted = arr->value[index];
  if (arr->size == 1)
  {
    free(arr->value);
    arr->value = NULL;
  }
  else
  {
    for (int i = index; i + 1 < arr->size; i++)
      arr->value[i] = arr->value[i + 1];

    int *tmp = realloc(arr->value, (arr->size - 1) * sizeof(int));

    if (tmp == NULL)
    {
      printf("Unexpected error with realloc(). Value deleted, Memory not freed!\n");
      return deleted;
    }
    arr->value = tmp;
  }

  arr->size--;
  return deleted;
}

int *find(const Array *const arr, int val)
{
  for (int i = 0; i < arr->size; i++)
  {
    if (val == arr->value[i])
      return arr->value + i;
  }
  return NULL;
}

int *maxInArr(const Array *const arr)
{
  int *max_val = arr->value;
  for (int i = 0; i < arr->size; i++)
  {
    if (*max_val < arr->value[i])
      max_val = arr->value + i;
  }
  return max_val;
}

int *minInArr(const Array *const arr)
{
  int *min_val = arr->value;
  for (int i = 0; i < arr->size; i++)
  {
    if (*min_val > arr->value[i])
      min_val = arr->value + i;
  }
  return min_val;
}

bool reverseArr(const Array *const arr)
{
  for (int i = 0; i < arr->size / 2; i++)
  {
    int tmp = arr->value[i];
    arr->value[i] = arr->value[arr->size - 1 - i];
    arr->value[arr->size - 1 - i] = tmp;
  }
  return true;
}

void sort(const Array *const arr)
{
  // implement Merge Sort for the arr.
  // Currently using diff sort algo
  for (int i = 0; i < arr->size; i++)
    for (int j = i + 1; j < arr->size; j++)
      if (arr->value[i] > arr->value[j])
      {
        int tmp = arr->value[i];
        arr->value[i] = arr->value[j];
        arr->value[j] = tmp;
      }
}

void rsort(const Array *const arr)
{
  // implement Merge Sort for the arr.
  // Currently using diff sort algo
  for (int i = 0; i < arr->size; i++)
    for (int j = i + 1; j < arr->size; j++)
      if (arr->value[i] < arr->value[j])
      {
        int tmp = arr->value[i];
        arr->value[i] = arr->value[j];
        arr->value[j] = tmp;
      }
}

int *BinarySearch(Array *arr, int key)
{
  // Array must be sorted.
  // use sort() before using this.
  int low = 0;
  int high = arr->size - 1;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    if (key == arr->value[low])
    {
      return arr->value + low;
    }
    else if (key == arr->value[high])
    {
      return arr->value + high;
    }
    else if (key == arr->value[mid])
    {
      return arr->value + mid;
    }
    else if (arr->value[mid] > key)
    {
      low++;
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
      high--;
    }
  }
  return NULL;
}

bool separateNegPos(Array *arr)
{
  int lftIdx = 0;
  int rhtIdx = arr->size - 1;

  while (lftIdx < rhtIdx)
  {
    if (arr->value[lftIdx] < 0)
      lftIdx++;
    if (arr->value[rhtIdx] >= 0)
      rhtIdx--;

    if (arr->value[lftIdx] > 0 && arr->value[rhtIdx] < 0)
    {
      int tmp = arr->value[lftIdx];
      arr->value[lftIdx] = arr->value[rhtIdx];
      arr->value[rhtIdx] = tmp;
      lftIdx++;
      rhtIdx--;
    }
  }
  return true;
}

////////////////////////////////////////////////

int main()
{
  Array *arr = createArr(5);

  for (int i = 0; i < arr->size; i++)
    arr->value[i] = 3 + (i * 100 + (i * i * i) - (i * i) * 12) % 12;

  displayArr(arr);

  append(arr, 24);
  displayArr(arr);

  insert(arr, 7, 12);
  insert(arr, 2, 12);
  insert(arr, arr->size, 69);
  displayArr(arr);

  delete(arr, 20);
  delete(arr, 2);
  displayArr(arr);

  Array *arr2 = createArr(1);
  printf("Address: %p\n", arr2);
  delete(arr2, 0);
  displayArr(arr2);
  freeArr(&arr2);
  printf("Address: %p\n", arr2);

  int *ptr = find(arr, 24);
  if (ptr)
    printf("%d is found!\n", *ptr);
  else
    printf("Not Found!\n");

  ptr = find(arr, 34);
  if (ptr)
    printf("%d is found!\n", *ptr);
  else
    printf("Not Found!\n");

  printf("Max in the array : %d\n", *maxInArr(arr));
  printf("Max in the array : %d\n", *minInArr(arr));

  displayArr(arr);
  printf("Reversed arr:\n");
  reverseArr(arr);
  displayArr(arr);

  sort(arr);
  displayArr(arr);
  printf("Size: %lu\n", arr->size);

  ptr = BinarySearch(arr, 11);
  if (ptr)
    printf("%d is found!\n", *ptr);
  else
    printf("Not Found!\n");

  rsort(arr);
  displayArr(arr);

  freeArr(&arr);

  Array *arr3 = createArr(10);
  for (int i = 0; i < arr3->size; i++)
  {
    arr3->value[i] = (i + 1) * (i % 2 ? -1 : 1);
  }
  displayArr(arr3);
  separateNegPos(arr3);
  displayArr(arr3);
  freeArr(&arr3);

  return 0;
}
