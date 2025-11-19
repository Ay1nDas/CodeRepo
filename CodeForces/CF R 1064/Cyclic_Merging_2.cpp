#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

long long solve()
{
  int n;
  cin >> n;
  vector<long long> values(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> values[i];
  }

  if (n == 1)
  {
    return 0;
  }

  vector<int> L(n), R(n);
  for (int i = 0; i < n; ++i)
  {
    L[i] = (i == 0) ? (n - 1) : (i - 1);
    R[i] = (i == n - 1) ? 0 : (i + 1);
  }

  set<pair<long long, int>> s;
  vector<long long> cost(n);
  vector<bool> alive(n, true);

  for (int i = 0; i < n; ++i)
  {
    cost[i] = max(values[i], values[R[i]]);
    s.insert({cost[i], i});
  }

  long long total_cost = 0;
  int merges_done = 0;

  while (merges_done < n - 1)
  {
    auto it = s.begin();
    long long C = it->first;
    int u = it->second;
    s.erase(it);

    if (!alive[u])
    {
      continue;
    }

    int v = R[u];

    total_cost += C;
    merges_done++;

    if (merges_done == n - 1)
    {
      break;
    }

    int p = L[u];
    int q = R[v];

    s.erase({cost[p], p});
    s.erase({cost[v], v});

    alive[v] = false;
    values[u] = max(values[u], values[v]);

    R[p] = u;
    L[u] = p;
    R[u] = q;
    L[q] = u;

    cost[p] = max(values[p], values[R[p]]);
    cost[u] = max(values[u], values[R[u]]);

    s.insert({cost[p], p});
    s.insert({cost[u], u});
  }

  return total_cost;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    cout << solve() << "\n";
  }
  return 0;
}