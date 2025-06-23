#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define all(x) (x).begin(), (x).end()
int mod = 1000000007;

int main()
{

  fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    ll n, m;
    cin >> n >> m;

    ll upperLim = 0;
    for (int i = 1; i <= n; i++)
      upperLim += i;

    if (m < n || m > upperLim)
    {
      cout << -1 << endl;
      continue;
    }

    ll max_node = n;
    ll sum = n;
    ll idx = 0;
    vector<ll> divine(n, 1);

    while (sum < m)
    {
      divine.at(idx) = max_node;
      sum += max_node - 1;

      while (sum > m)
      {
        sum--;
        divine.at(idx)--;
      }

      idx++;
      max_node--;
    }
    cout << divine.at(0) << endl;

    unordered_map<ll, ll> used;
    used[divine.at(0)]++;
    idx = 1;

    for (idx = 1; idx < n && divine.at(idx) != 1; idx++)
    {
      cout << divine.at(0) << " " << divine.at(idx) << endl;
      used[divine.at(idx)]++;
    }

    if (!used[1])
      cout << divine.at(idx - 1) << " " << 1 << endl;

    for (int i = 2; i <= n; i++)
    {
      if (!used[i])
        cout << 1 << " " << i << endl;
    }
  }

  return 0;
}