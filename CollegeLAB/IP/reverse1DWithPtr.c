#include <stdio.h>
#include <stdlib.h>

int main()
{
  // printf("Hello!");
  int n = 5;
  int arr1[5] = {1, 2, 3, 4, 5};
  int *arrPtr = &arr1[0];

  int rev[5];
  int *revPtr = &rev[n - 1];

  for (int i = 0; i < n; i++)
  {
    *revPtr = *arrPtr;
    // printf("%d ", *arrPtr);
    arrPtr++;
    revPtr--;
  }

  revPtr = &rev[0];

  for (int i = 0; i < n; i++)
  {
    printf("%d ", *revPtr++);
  }

  return 0;
}