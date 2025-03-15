#include <stdio.h>
#include <stdlib.h>

int main()
{
  float a, b;
  printf("Enter two float numbers: ");
  scanf("%f %f", &a, &b);
  printf("The product of the two numbers is: %f\n", a * b);
  return 0;
}