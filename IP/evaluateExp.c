// f(x)=x-x3/3!+x5/5!-x7/7!+..

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fact(int num)
{
  if (num < 2)
  {
    return 1;
  }

  return num * fact(num - 1);
}

int main()
{

  int x = 0;
  printf("Enter x for f(x): ");
  scanf("%d", &x);

  int terms = 0;
  printf("Enter the number of terms: ");
  scanf("%d", &terms);

  double value = 0;
  for (int i = 0; i < terms; i++)
  {
    value += pow(-1, i) * (pow(x, i * 2 + 1) / fact(i * 2 + 1));
  }

  printf("Value: %f", value);
  return 0;
}