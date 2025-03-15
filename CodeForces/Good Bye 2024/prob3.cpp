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
    ll n, k;
    cin >> n >> k;
    double spacing = n;

    // ll div_by_2 = 1;

    while (spacing >= k)
      spacing /= 2;

    ll total = 0;

    // cout << spacing << endl
    //  << endl;

    for (int i = 1; i * spacing < n; i++)
    {
      if (static_cast<int>(spacing * i) != spacing * i)
      {
        total += static_cast<int>(spacing * i) + 1;
      }
    }

    cout << total << endl;
  }

  return 0;
}