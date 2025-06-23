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
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;

    int max = 0;

    if (x <= y)
    {
      if (k >= a)
      {
        max += (k - a) / x + 1;
        k = a + (k - a) % x - x;
      }
      if (k >= b)
        max += (k - b) / y + 1;
    }
    else
    {
      if (k >= b)
      {
        max += (k - b) / y + 1;
        k = b + (k - b) % y - y;
      }
      if (k >= a)
        max += (k - a) / x + 1;
    }

    cout << max << endl;
  }

  return 0;
}