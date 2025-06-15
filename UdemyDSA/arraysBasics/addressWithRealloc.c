#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *ptr = malloc(1 * sizeof(int));
  printf("%p\n", ptr);

  for (int i = 2; i < 10000000; i += i)
  {
    ptr = realloc(ptr, i * sizeof(int));
    printf("%p\n", ptr);
  }

  return 0;
}