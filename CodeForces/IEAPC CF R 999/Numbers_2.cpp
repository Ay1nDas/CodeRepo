#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define all(x) (x).begin(), (x).end()
int mod = 998244353;

int main()
{

  fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    int n, m;
    cin >> n >> m;

    map<ll, ll> val;

    for (int i = 0; i < n; i++)
    {
      int v;
      cin >> v;
      val[v]++;
    }
    for (int i = 0; i < m; i++)
    {
      int v;
      cin >> v;
      val[v]--;
    }

    auto it = val.begin();
    for (; it != val.end() && it->second > 0; it++)
    {
      if (it->second > 0)
      {
        int pre_key = it->first;
        int pre_val = it->second;
        it++;

        if (val[pre_key + it->first] < 0)
        {
          pre_val += val[pre_key + it->first];
          it->second += val[pre_key + it->first];
        }
      }
    }
  }

  return 0;
}