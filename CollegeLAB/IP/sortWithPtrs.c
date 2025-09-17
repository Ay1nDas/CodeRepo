#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int n)
{
  int temp;

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (*(arr + i) > *(arr + j))
      {
        temp = *(arr + i);
        *(arr + i) = *(arr + j);
        *(arr + j) = temp;
      }
    }
  }
}

int main()
{

  int arr[] = {1, 3, 5, 2, -1, 12};

  sort(arr, sizeof(arr) / sizeof(arr[0]));

  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}