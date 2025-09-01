#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int low, int mid, int high)
{
  int *tmp = malloc((high - low + 1) * sizeof(int));
  int idx = 0;

  int i = low, j = mid + 1;

  while (i <= mid && j <= high)
    tmp[idx++] = (arr[i] > arr[j] ? arr[j++] : arr[i++]);

  while (i <= mid)
    tmp[idx++] = arr[i++];
  while (j <= high)
    tmp[idx++] = arr[j++];

  for (int k = low; k <= high; k++)
    arr[k] = tmp[k - low];

  free(tmp);
}

void mergeSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
  }
}

int main()
{
  int arr[] = {7, 6, 5, 4, 3, 2, 1};
  mergeSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);

  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
