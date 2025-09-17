#include <stdio.h>
#include <stdlib.h>

int main()
{
  int arr[] = {3, 6, 4, 33, 2, 69, 1, 9};

  int max = arr[0];

  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
  {
    if (max < arr[i])
      max = arr[i];
  }

  printf("max: %d", max);
  return 0;
}