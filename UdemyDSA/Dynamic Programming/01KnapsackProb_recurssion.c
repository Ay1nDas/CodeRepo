#include <stdio.h>
#include <stdlib.h>

int getProfit(int i, int m, int p[], int w[])
{
  if (i == -1)
    return 0;

  int notIncluded = getProfit(i - 1, m, p, w);
  int included = m < w[i] ? 0 : (getProfit(i - 1, m - w[i], p, w) + p[i]);

  printf("i: %d, %d | %d\n", i, notIncluded, included);

  return included > notIncluded ? included : notIncluded;
}

int main()
{
  int n = 4, m = 8;
  int p[] = {1, 2, 5, 6};
  int pSize = sizeof(p) / sizeof(p[0]);

  int w[] = {2, 3, 4, 5};
  int wSize = sizeof(w) / sizeof(p[0]);

  int maxProfit = getProfit(n - 1, m, p, w);

  printf("ANS: %d\n", maxProfit);

  return 0;
}