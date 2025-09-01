#include <bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int start, int end)
{
  if (start == end)
    return;

  int pivot = arr[start];
  int l = start, r = end;

  do
  {
    do
    {
      l++;
    } while (arr[l] <= pivot && l < r);
    do
    {
      r--;
    } while (arr[r] > pivot);

    if (l < r)
    {
      int tmp = arr[l];
      arr[l] = arr[r];
      arr[r] = tmp;
    }

  } while (l < r);

  arr[start] = arr[r];
  arr[r] = pivot;

  quickSort(arr, start, r);
  quickSort(arr, r + 1, end);
}

int main()
{
  int arr[] = {50, 70, 60, 90, 40, 80, 10, 20, 30, 50, 80, 10, 90};
  quickSort(arr, 0, sizeof(arr) / sizeof(arr[0]));

  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}