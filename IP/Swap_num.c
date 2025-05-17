#include <stdio.h>
#include <stdlib.h>

int main()
{
  int num1, num2;
  printf("Enter the numbers: ");
  scanf("%d %d", &num1, &num2);

  num1 = num1 + num2;
  num2 = num1 - num2;
  num1 = num1 - num2;

  printf("The numbers after swapping are: %d %d", num1, num2);
  return 0;
}