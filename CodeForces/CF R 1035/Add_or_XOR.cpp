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
    ll a, b, x, y;
    cin >> a >> b >> x >> y;

    if (a > b + 1)
    {
      cout << -1 << endl;
      continue;
    }
    else if (a == b + 1 && a % 2 == 0)
    {
      cout << -1 << endl;
      continue;
    }
    else if (a == b + 1 && a % 2 == 1)
    {
      cout << y << endl;
      continue;
    }
    else if (a == b)
    {
      cout << 0 << endl;
      continue;
    }

    ll diff = b - a;

    if (x <= y)
    {
      cout << diff * x << endl;
    }
    else if (a % 2)
    {
      cout << x * ((diff + 1) / 2) + y * (diff / 2) << endl;
    }
    else
    {
      cout << y * ((diff + 1) / 2) + x * (diff / 2) << endl;
    }
  }

  return 0;
}