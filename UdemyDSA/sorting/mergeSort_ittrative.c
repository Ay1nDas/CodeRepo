#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[], int arrSize)
{
  int lstSz;
  for (lstSz = 2; lstSz <= arrSize; lstSz *= 2)
  {
    for (int i = 0; i + lstSz <= arrSize; i += lstSz)
    {
      // printf("HERE!\n");
      int l1 = i;
      int l2 = i + lstSz / 2;

      int *sortedList = malloc(lstSz * sizeof(int));
      int idx = 0;

      while (l1 < i + lstSz / 2 && l2 < i + lstSz)
      {
        sortedList[idx++] = (arr[l1] < arr[l2] ? arr[l1++] : arr[l2++]);
      }

      while (l1 < i + lstSz / 2)
        sortedList[idx++] = arr[l1++];

      while (l2 < i + lstSz)
        sortedList[idx++] = arr[l2++];

      for (int j = i; j < i + lstSz; j++)
        arr[j] = sortedList[j - i];

      free(sortedList);
    }

    // for (int k = 0; k < arrSize; k++)
    // {
    //   printf("%d ", arr[k]);
    // }
    // printf("\n");
  }

  if (lstSz / 2 < arrSize)
  {
    if (arrSize - lstSz / 2 > 2)
      mergeSort(&arr[lstSz / 2], arrSize - lstSz / 2);

    int l1 = 0;
    int l2 = lstSz / 2;

    int *sortedList = malloc(arrSize * sizeof(int));
    int idx = 0;
    // printf("arr[l2] = %d\n", arr[l2]);

    while (l1 < lstSz / 2 && l2 < arrSize)
    {
      sortedList[idx++] = (arr[l1] < arr[l2] ? arr[l1++] : arr[l2++]); // Check this.
    }

    while (l1 < lstSz / 2)
      sortedList[idx++] = arr[l1++];

    while (l2 < arrSize)
      sortedList[idx++] = arr[l2++];

    for (int j = 0; j < arrSize; j++)
    {
      // printf("%d ", sortedList[j]);
      arr[j] = sortedList[j];
    }
    // printf("\n");

    free(sortedList);
  }
}

int main()
{
  int arr[] = {7, 6, 5, 4, 3, 2, 1};
  mergeSort(arr, sizeof(arr) / sizeof(arr[0]));

  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}
