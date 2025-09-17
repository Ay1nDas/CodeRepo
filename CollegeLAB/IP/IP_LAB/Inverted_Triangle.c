#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  printf("n: ");
  scanf("%d", &n);

  for (int i = n; i > 0; i--)
  {
    for (int j = 1; j <= n - i; j++)
    {
      printf(" ");
    }

    for (int j = 1; j <= i; j++)
    {
      printf("* ");
    }
    printf("\n");
  }
  return 0;
}