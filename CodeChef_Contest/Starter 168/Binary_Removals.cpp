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
    ll n, x, k;
    cin >> n >> x >> k;
    string bi;
    cin >> bi;

    ll inversion = 0, oneCount = 0;

    for (int i = 0; i < n; i++)
    {
      if (bi.at(i) == '1')
      {
        oneCount++;
      }
      else
      {
        inversion += oneCount;
      }
    }

    if (inversion <= x && inversion % k == 0)
    {
      cout << 1 << endl;
    }
    else
    {
      cout << 2 << endl;
    }
  }

  return 0;
}