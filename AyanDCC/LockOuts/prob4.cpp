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
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int total_coins = 0;

  if (e > f)
  {
    int suits = min(a, d);
    total_coins += suits * e;

    if (d > suits)
    {
      total_coins += min(min((d - suits), b), c) * f;
    }
  }
  else
  {
    int suits = min(min(b, c), d);
    total_coins += suits * f;

    if (d > suits)
    {
      total_coins += min((d - suits), a) * e;
    }
  }

  cout << total_coins << endl;

  return 0;
}