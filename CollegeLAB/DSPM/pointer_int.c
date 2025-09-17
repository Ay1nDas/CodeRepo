#include <stdio.h>
#include <stdlib.h>

int main()
{

  int arr[] = {1, 2, 3, 4, 7};
  int *p = arr, *q = &arr[3];

  printf("%p\n", q - p);
  printf("%ld\n", q - p);

  return 0;
}