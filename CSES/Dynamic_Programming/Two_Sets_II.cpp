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
ll inv_2 = 500000004;

int main()
{

  fast_io;
  int n;
  cin >> n;

  ll total = n * (n + 1) / 2;
  vector<ll> sums(total + 1);
  int maxIdx = 0;
  sums.at(0) = 1;

  for (int i = 1; i <= n; i++)
  {
    maxIdx += i;
    for (int j = maxIdx; j >= i; j--)
    {
      // cout << j << " ";
      sums.at(j) = (sums.at(j) + sums.at(j - i)) % mod;
    }
    // cout << endl;
  }
  if (total % 2 == 1)
  {
    cout << 0 << endl;
  }
  else
  {
    cout << (sums.at(total / 2) * inv_2) % mod << endl;
  }

  return 0;
}