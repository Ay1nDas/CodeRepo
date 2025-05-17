//     *
//    ***
//   *****
//  *******
// *********

#include <stdio.h>
#include <stdlib.h>

int main()
{

  int lines = 0;
  printf("Enter number of lines: ");
  scanf("%d", &lines);

  for (int i = 0; i < lines; i++)
  {

    for (int j = 0; j < (lines - i - 1); j++)
      printf(" ");

    for (int j = 0; j < i * 2 + 1; j++)
      printf("*");

    printf("\n");
  }

  return 0;
}