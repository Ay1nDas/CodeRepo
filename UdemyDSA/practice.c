#include <stdio.h>
#include <stdlib.h>

struct rectangle
{
  int length;
  int breath;
};

struct rectangle create_rectangle(int l, int b)
{
  struct rectangle r;
  r.length = l;
  r.breath = b;
  return r;
}

int main()
{
  struct rectangle r1 = create_rectangle(10, 5);
  printf("%d\n", r1.length);
  printf("%d\n", r1.breath);

  return 0;
}