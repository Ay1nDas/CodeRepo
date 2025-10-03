#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
int mod = 1000000007;

int main()
{
  int n, x;
  scanf("%d %d", &n, &x);

  int *coins = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    scanf("%d", coins + i);

  ll *ways = calloc(x + 1, sizeof(ll));
  ways[0] = 1;

  for (int i = 1; i < x + 1; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (coins[j] > i)
        continue;

      ways[i] = (ways[i] + ways[i - coins[j]]) % mod;
    }
  }

  printf("%lld\n", ways[x]);

  return 0;
}