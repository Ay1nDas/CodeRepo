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
    ll n, l, r, k;
    cin >> n >> l >> r >> k;

    if (n % 2)
    {
      cout << l << endl;
      continue;
    }
    else if (n == 2)
    {
      cout << -1 << endl;
    }
    else
    {
      ll a = l;
      ll b = 1;
      while (a)
      {
        a /= 2;
        b *= 2;
      }

      if (b <= r && n > 3)
      {
        cout << (k < n - 1 ? l : b) << endl;
      }
      else
      {
        cout << -1 << endl;
      }
    }
  }

  return 0;
}

// ll ret_a = 0, ret_b = 0;
// bool isFound = false;

// for (ll a = l; a <= r; ++a)
// {
//   for (ll b = a + 1; b <= r && b - a <= 60; ++b)
//   {
//     if ((a & b) == 0)
//     {
//       ret_a = a, ret_b = b;
//       isFound = true;
//       break;
//     }
//   }
//   if (isFound)
//     break;
// }