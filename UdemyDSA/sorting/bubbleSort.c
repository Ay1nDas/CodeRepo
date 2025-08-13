#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int arrSize)
{
  while (arrSize--)
  {
    for (int j = 0; j < arrSize; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
}

int main()
{
  int arr[] = {5, 3, 7, 8, 2};
  bubbleSort(arr, sizeof(arr) / sizeof(arr[0]));

  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
