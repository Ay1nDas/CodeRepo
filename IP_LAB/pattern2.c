// 1
// 22
// 333
// 4444
// 55555

#include <stdio.h>

int main()
{
  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i += 2)
  {

    for (int j = 1; j <= (n - i) / 2; j++)
    {
      printf(" ");
    }

    for (int j = 1; j <= i; j++)
    {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}