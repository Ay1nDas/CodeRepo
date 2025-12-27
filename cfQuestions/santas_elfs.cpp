#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 11
#define int long long
#endif

// ================= DSU =================
struct DSU
{
  vector<int> par, sz;

  DSU(int n)
  {
    par.resize(n);
    sz.assign(n, 1);
    iota(all(par), 0);
  }

  int find_par(int u)
  {
    if (par[u] == u)
      return u;
    return par[u] = find_par(par[u]);
  }

  void merge(int u, int v)
  {
    u = find_par(u);
    v = find_par(v);
    if (u == v)
      return;
    if (sz[u] < sz[v])
      swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
  }

  void reset(int u)
  {
    par[u] = u;
    sz[u] = 1;
  }
};

void solve()
{
  int n, first, m;
  cin >> n >> first >> m;

  vector<vector<int>> meetings(m, vector<int>(3));
  for (int i = 0; i < m; i++)
    cin >> meetings[i][0] >> meetings[i][1] >> meetings[i][2];

  sort(all(meetings), [](const vector<int> &a, const vector<int> &b)
       { return a[2] < b[2]; });

  DSU dsu(n);
  dsu.merge(0, first); // source of secret

  for (int l = 0; l < m;)
  {
    int r = l;
    while (r < m && meetings[r][2] == meetings[l][2])
    {
      dsu.merge(meetings[r][0], meetings[r][1]);
      r++;
    }

    int root0 = dsu.find_par(0);

    // reset elves not connected to root0 at this time
    for (int i = l; i < r; ++i)
    {
      int u = meetings[i][0], v = meetings[i][1];
      if (dsu.find_par(u) != root0)
        dsu.reset(u);
      if (dsu.find_par(v) != root0)
        dsu.reset(v);
    }

    l = r;
  }

  int root0 = dsu.find_par(0);
  vector<int> remaining;
  for (int i = 0; i < n; ++i)
    if (dsu.find_par(i) != root0)
      remaining.push_back(i);

  if (remaining.empty())
  {
    cout << "YES\n";
  }
  else
  {
    sort(remaining.begin(), remaining.end());
    cout << "NO\n";
    cout << remaining.size() << "\n";
    for (int x : remaining)
      cout << x << " ";
    cout << "\n";
  }
}

int32_t main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--)
    solve();
  return 0;
}
