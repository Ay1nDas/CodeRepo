#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  scanf("%d", &n);

  int is_prime = 1;

  for (int i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
    {
      is_prime = 0;
      break;
    }
  }

  return 0;
}