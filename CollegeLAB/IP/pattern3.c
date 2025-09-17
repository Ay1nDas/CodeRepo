//   1
//  121
// 12321

// 1
// 22
// 333
// 4444
// 55555

#include <stdio.h>

int main()
{
  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i += 2)
  {

    for (int j = 1; j <= (n - i) / 2; j++)
    {
      printf(" ");
    }

    for (int j = 1; j <= i; j++)
    {
      if (j > (i + 1) / 2)
        printf("%d", i - j + 1);
      else
        printf("%d", j);
    }
    printf("\n");
  }

  return 0;
}