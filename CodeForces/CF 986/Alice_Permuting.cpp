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
    ll n, b, c;
    cin >> n >> b >> c;

    if (b == 0 && c < n - 2)
    {
      cout << -1 << endl;
      continue;
    }
    else if (b == 0 && c >= n - 2 && c < n)
    {
      cout << n - 1 << endl;
      continue;
    }
    else if (b == 0 && c >= n)
    {
      cout << n << endl;
      continue;
    }

    ll x = (n - 1 - c) / b;
    if (n - 1 - c < 0)
      x = 0;
    else
      x++;

    ll operations = n - x;

    cout << operations << endl;
  }

  return 0;
}