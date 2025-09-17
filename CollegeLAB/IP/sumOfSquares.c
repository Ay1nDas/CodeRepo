#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n = 0;
  printf("Enter n:");
  scanf("%d", &n);

  int sum = 0;

  for (int i = 1; i <= n; i++)
  {
    sum += (i * 2) * (i * 2);
  }

  printf("Sum : %d", sum);

  return 0;
}