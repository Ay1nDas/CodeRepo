#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
  if (b % a == 0)
    return a;

  return gcd(b % a, a);
}

int main()
{
  int num1 = 102, num2 = 12;

  printf("gcd: %d", gcd(num1, num2));

  return 0;
}