#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int arrSize)
{
  for (int i = 1; i < arrSize; i++)
  {
    for (int j = i; j > 0; j--)
    {
      if (arr[j - 1] > arr[j])
      {
        int tmp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = tmp;
      }
      else
      {
        break;
      }
    }
  }
}

int main()
{
  int arr[] = {8, 5, 7, 3, 2};
  insertionSort(arr, sizeof(arr) / sizeof(arr[0]));

  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
