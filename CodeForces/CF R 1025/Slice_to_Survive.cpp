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
    ll m, n, a, b;
    cin >> m >> n >> a >> b;

    ll h = max(b - 1, n - b) * m;
    ll v = max(a - 1, m - a) * n;

    if (h > v)
      n -= h / m;
    else
      m -= v / n;

    ll cnt = 1;

    // cout << m << " " << n << endl;

    while (m != 1 || n != 1)
    {
      a = (m + 1) / 2;
      b = (n + 1) / 2;

      h = max(b - 1, n - b) * m;
      v = max(a - 1, m - a) * n;

      if (h > v)
        n -= h / m;
      else
        m -= v / n;

      cnt++;
    }

    cout << cnt << endl;
  }

  return 0;
}
