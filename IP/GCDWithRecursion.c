#include <stdio.h>
#include <stdlib.h>

int gcd(int num1, int num2)
{
  if (num2 % num1 == 0)
  {
    return num1;
  }

  return gcd(num2 % num1, num1);
}

int main()
{
  int a, b;
  printf("Enter two numbers: ");
  scanf("%d%d", &a, &b);

  printf("GCD of %d, %d is: %d", a, b, gcd(a, b));

  return 0;
}