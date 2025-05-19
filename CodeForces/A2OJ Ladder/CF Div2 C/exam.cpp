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
  ll max_a = 0;
  map<ll, vector<ll>> date;
  while (T--)
  {
    ll a, b;
    cin >> a >> b;
    date[a].push_back(b);
    max_a = max(a, max_a);
  }

  ll pre_date = 0;
  for (auto &pair : date)
  {
    sort(pair.second.begin(), pair.second.end());
    for (auto value : pair.second)
    {
      if (pre_date <= value)
        pre_date = value;
      else
        pre_date = pair.first;
    }
  }
  cout << pre_date << endl;

  return 0;
}