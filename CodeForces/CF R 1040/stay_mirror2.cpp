#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10010;

class BIT
{
public:
  vector<int> tree;
  int n;
  BIT(int size)
  {
    n = size + 2;
    tree.assign(n, 0);
  }
  void update(int i, int val)
  {
    while (i < n)
    {
      tree[i] += val;
      i += i & -i;
    }
  }
  int query(int i)
  {
    int res = 0;
    while (i > 0)
    {
      res += tree[i];
      i -= i & -i;
    }
    return res;
  }
  int range_query(int l, int r)
  {
    return query(r) - query(l - 1);
  }
};

void solve()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> p(n);
    set<int> all_vals;
    for (int i = 0; i < n; ++i)
    {
      cin >> p[i];
      all_vals.insert(p[i]);
      all_vals.insert(2 * n - p[i]);
    }

    // Coordinate compression
    vector<int> sorted_vals(all_vals.begin(), all_vals.end());
    unordered_map<int, int> val_to_idx;
    for (int i = 0; i < sorted_vals.size(); ++i)
      val_to_idx[sorted_vals[i]] = i + 1;

    int sz = sorted_vals.size();
    vector<vector<int>> dp(n, vector<int>(2, 1e9));
    vector<BIT> bits(2, BIT(sz + 2));

    // First element
    int v0 = val_to_idx[p[0]];
    int v1 = val_to_idx[2 * n - p[0]];
    dp[0][0] = 0;
    dp[0][1] = 0;
    bits[0].update(v0, 1);
    bits[1].update(v1, 1);

    for (int i = 1; i < n; ++i)
    {
      vector<BIT> new_bits(2, BIT(sz + 2));
      vector<vector<int>> new_dp(1, vector<int>(2, 1e9));
      for (int prev = 0; prev < 2; ++prev)
      {
        for (int cur = 0; cur < 2; ++cur)
        {
          int ai = (cur == 0 ? p[i] : 2 * n - p[i]);
          int ai_idx = val_to_idx[ai];
          int inversions = bits[prev].query(sz) - bits[prev].query(ai_idx);
          new_dp[0][cur] = min(new_dp[0][cur], dp[i - 1][prev] + inversions);
          new_bits[cur].update(ai_idx, 1);
        }
      }
      dp[i] = new_dp[0];
      bits = new_bits;
    }

    for (auto i : bits)

      cout << min(dp[n - 1][0], dp[n - 1][1]) << '\n';
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
