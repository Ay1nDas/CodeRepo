#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i;
  char c;
  float f;
  printf("Enter an integer: ");
  scanf("%d", &i);

  char garbage;
  scanf("%c", &garbage);

  printf("Enter a char: ");
  scanf("%c", &c);
  printf("Enter a float: ");
  scanf("%f", &f);
  printf("The integer is %d, the char is: %c, the float is %f\n", i, c, f);

  return 0;
}