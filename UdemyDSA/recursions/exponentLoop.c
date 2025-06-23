#include <stdio.h>
#include <stdlib.h>

long long power(long long a, long long b)
{
  long long remainderMultiply = 1;
  while (b > 1)
  {
    if (b % 2 == 0)
    {
      a *= a;
      b /= 2;
    }
    else
    {
      remainderMultiply *= a;
      a *= a;
      b = (b - 1) / 2; // --b/=2?
    }
  }
  return remainderMultiply * a;
}

int main()
{
  printf("Power: %lld\n", power(2, 30));
  return 0;
}