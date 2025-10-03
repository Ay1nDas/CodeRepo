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
  vector<ll> dp(n + 1);
  dp.at(1) = 1;
  dp.at(0) = 1;

  for (int i = 2; i <= n; i++)
  {
    for (int k = 1; k <= i && k <= 6; k++)
    {
      dp.at(i) = (dp.at(i) + dp.at(i - k) % mod) % mod;
    }
  }

  cout << dp.at(n) << endl;

  return 0;
}