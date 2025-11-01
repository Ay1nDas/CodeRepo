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
  int n;
  cin >> n;

  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr.at(i);
  }

  vector<vector<ll>> dp(n + 1, vector<ll>(n));
  int turn = 0;

  if (n % 2 == 1)
  {
    turn = 2;
    for (int i = 0; i < n; i++)
    {
      dp.at(1).at(i) = arr.at(i);
    }
  }
  else
  {
    turn = 1;
  }

  for (int i = 2; i <= n; i++)
  {
    for (int j = 0; j < n - i + 1; j++)
    {
      if (turn == 1)
      {
        ll lVal = arr.at(j) + dp.at(i - 1).at(j + 1);
        ll rVal = arr.at(i + j - 1) + dp.at(i - 1).at(j);

        dp.at(i).at(j) = max(lVal, rVal);
      }
      else if (turn == 2)
      {
        ll lVal = dp.at(i - 1).at(j + 1);
        ll rVal = dp.at(i - 1).at(j);

        dp.at(i).at(j) = min(lVal, rVal);
      }
    }

    turn = (turn == 1 ? 2 : 1);
  }

  // for (auto vec : dp)
  // {
  //   for (auto i : vec)
  //   {
  //     cout << i << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  cout << dp.at(n).at(0) << endl;

  return 0;
}