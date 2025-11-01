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
    ll n, x;
    cin >> n >> x;
    vector<ll> prices(n);
    vector<ll> arrangedPrice(n);
    int arrPtr = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> prices.at(i);
    }

    sort(prices.rbegin(), prices.rend());

    // for (auto i : prices)
    //   cout << i << " ";
    // cout << endl;

    if (prices.size() == 1)
    {
      if (x <= prices.at(0))
      {
        cout << prices.at(0) << endl;
      }
      else
      {
        cout << 0 << endl;
      }
      cout << prices.at(0) << endl;
      continue;
    }

    ll excess = 0;
    ll totalPts = 0;

    int fr = 0, bk = prices.size() - 1;

    while (fr < bk)
    {
      ll reqd = x - (excess + prices.at(fr));
      excess = 0;

      while (fr < bk && reqd > 0)
      {
        reqd -= prices.at(bk);
        arrangedPrice.at(arrPtr++) = prices.at(bk--);
      }

      if (reqd < 0)
      {
        excess = -reqd;
        reqd = 0;
      }

      if (reqd == 0LL)
      {
        totalPts += prices.at(fr);
        arrangedPrice.at(arrPtr++) = prices.at(fr++);
      }
    }

    for (int i = fr; i <= bk; i++)
    {
      excess += prices.at(i);
      if (excess >= x)
      {
        totalPts += prices.at(i);
      }
      arrangedPrice.at(arrPtr++) = prices.at(i);
    }

    cout << totalPts << endl;
    for (auto i : arrangedPrice)
    {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}