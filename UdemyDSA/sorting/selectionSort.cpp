#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int arrSize)
{
  for (int i = 0; i < arrSize; i++)
  {
    int k = i;

    for (int j = i + 1; j < arrSize; j++)
    {
      if (arr[k] > arr[j])
        k = j;
    }

    if (k != i)
    {
      int tmp = arr[i];
      arr[i] = arr[k];
      arr[k] = tmp;
    }
  }
}

int main()
{
  int arr[] = {5, 3, 7, 8, 2};
  selectionSort(arr, sizeof(arr) / sizeof(arr[0]));

  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}