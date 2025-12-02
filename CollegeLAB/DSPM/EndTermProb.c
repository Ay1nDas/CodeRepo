#include <stdio.h>
int abc(int a)
{
  int b = 12;
  int c = (b = 0, 5);
  printf("%d %d", b, c);
  return (++a, a++);
}

int main()
{
  // printf("%d \n", abc(3.5));
  printf("Hello World" + 4);
  return 0;
}