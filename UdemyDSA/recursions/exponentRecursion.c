#include <stdio.h>
#include <stdlib.h>

long long power(long long a, long long b)
{
  if (b == 0)
  {
    return 1;
  }

  if (b % 2 == 0)
  {
    return power(a * a, b / 2);
  }
  else
  {
    return a * power(a * a, (b - 1) / 2);
  }
}

int main()
{
  printf("Power: %lld\n", power(2, 45));
  return 0;
}