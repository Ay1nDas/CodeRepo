#include <iostream>
#include <vector>
#include <algorithm>

void solve()
{
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::vector<std::vector<int>> positions(n + 1);
  for (int i = 0; i < n; ++i)
  {
    std::cin >> a[i];
    positions[a[i]].push_back(i);
  }

  std::vector<int> dp(n + 1, 0);
  std::vector<int> counts(n + 1);
  for (int k = 1; k <= n; ++k)
  {
    counts[k] = positions[k].size();
  }

  for (int i = n - 1; i >= 0; --i)
  {
    dp[i] = dp[i + 1];

    int k = a[i];
    counts[k]--;
    int p = counts[k];

    if (p + k - 1 < positions[k].size())
    {
      int j = positions[k][p + k - 1];
      int potential_length = k + dp[j + 1];

      dp[i] = std::max(dp[i], potential_length);
    }
  }

  std::cout << dp[0] << "\n";
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int t;
  std::cin >> t;
  while (t--)
  {
    solve();
  }

  return 0;
}