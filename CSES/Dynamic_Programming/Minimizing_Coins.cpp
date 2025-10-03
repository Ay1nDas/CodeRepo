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
  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  for (int i = 0; i < n; i++)
    cin >> coins.at(i);

  vector<int> minCoin(x + 1, -1);

  for (int i = 1; i < x + 1; i++)
  {
    int currCoin = INT_MAX;
    for (auto coin : coins)
    {
      if (coin < i && minCoin.at(i - coin) > 0)
        currCoin = min(currCoin, minCoin.at(i - coin) + 1);
      else if (coin == i)
        currCoin = 1;
    }

    if (currCoin != INT_MAX)
      minCoin.at(i) = currCoin;
  }

  // for (auto coin : minCoin)
  //   cout << coin << " ";
  // cout << endl;

  cout << minCoin.at(x) << endl;

  return 0;
}