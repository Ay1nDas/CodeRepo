#include <stdio.h>
#include <stdlib.h>

double max(double a, double b)
{
  return a > b ? a : b;
}

int main()
{
  int n = 4, m = 8;
  int p[] = {1, 2, 5, 6};
  int pSize = sizeof(p) / sizeof(p[0]);

  int w[] = {2, 3, 4, 5};
  int wSize = sizeof(w) / sizeof(p[0]);

  int dp[n + 1][m + 1];
  for (int i = 0; i < n + 1; i++)
    dp[i][0] = 0;

  for (int j = 0; j < m + 1; j++)
    dp[0][j] = 0;

  // for (int i = 0; i < n + 1; i++)
  // {
  //   for (int j = 0; j < m + 1; j++)
  //     printf("%d ", dp[i][j]);
  //   printf("\n");
  // }
  // printf("\n");

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      // printf("%d %d %d %d\n", i, j, p[i - 1], w[i - 1]);
      int notTaken = dp[i - 1][j];
      int taken = (w[i - 1] <= j ? dp[i - 1][j - w[i - 1]] + p[i - 1] : 0);

      // printf("%d %d\n", notTaken, taken);

      dp[i][j] = max(notTaken, taken);
    }
  }

  for (int i = 0; i < n + 1; i++)
  {
    for (int j = 0; j < m + 1; j++)
      printf("%d ", dp[i][j]);
    printf("\n");
  }
  printf("\n");

  printf("The max profit is: %d\n", dp[n][m]);

  return 0;
}