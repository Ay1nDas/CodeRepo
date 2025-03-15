#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  scanf("%d", &n);

  int rev = 0;

  while (n > 0)
  {
    rev *= 10;
    rev += n % 10;
    n /= 10;
  }

  printf("%d\n", rev);

  return 0;
}