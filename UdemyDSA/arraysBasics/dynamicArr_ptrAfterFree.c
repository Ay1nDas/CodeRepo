#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *ptr = malloc(5 * sizeof(int));

  for (int i = 0; i < 5; i++)
  {
    ptr[i] = i;
  }
  printf("%d\n", ptr[3]);
  int *loc = ptr + 3;

  free(ptr);

  printf("%ls\n", loc);

  return 0;
}
