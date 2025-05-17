#include <stdio.h>

// int main()
// {
//   int a = 5; // 0101 in binary
//   int b = 3; // 0011 in binary

//   printf("a & b = %d\n", a & b);   // 0001 = 1
//   printf("a | b = %d\n", a | b);   // 0111 = 7
//   printf("a ^ b = %d\n", a ^ b);   // 0110 = 6
//   printf("~a = %d\n", ~a);         // Inverts bits of a (result is -6 due to 2's complement)
//   printf("a << 1 = %d\n", a << 1); // 1010 = 10
//   printf("a >> 1 = %d\n", a >> 1); // 0010 = 2

//   return 0;
// }

void main()
{
  int m[2];
  int *p = m;
  m[0] = 100;
  m[1] = 200;
  printf("%d%d", ++*p, *p);
}