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
  for (auto &coin : coins)
    cin >> coin;

  ll *ways = (ll *)(calloc(x + 1, sizeof(ll)));
  ways[0] = 1;

  for (int i = 1; i < x + 1; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (coins[j] > i)
        continue;

      ways[i] = (ways[i] + ways[i - coins[j]]) % mod;
    }
  }

  cout << ways[x] << endl;
  return 0;
}
