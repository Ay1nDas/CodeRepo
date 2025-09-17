#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define all(x) (x).begin(), (x).end()
int mod = 998244353;

int main()
{

  fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    for (int i = 1; i <= n; i++)
      cin >> b[i];

    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= n; i++)
    {
      if (a[i - 1] <= a[i] && b[i - 1] <= b[i])
        dp[i][0] = (dp[i][0] + dp[i - 1][0]) % mod;
      if (a[i - 1] <= b[i] && b[i - 1] <= a[i])
        dp[i][1] = (dp[i][1] + dp[i - 1][0]) % mod;

      if (b[i - 1] <= a[i] && a[i - 1] <= b[i])
        dp[i][0] = (dp[i][0] + dp[i - 1][1]) % mod;
      if (b[i - 1] <= b[i] && a[i - 1] <= a[i])
        dp[i][1] = (dp[i][1] + dp[i - 1][1]) % mod;
    }

    cout << (dp[n][0] + dp[n][1]) % mod << endl;
  }

  return 0;
}