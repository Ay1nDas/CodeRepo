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

ll power(ll base, ll exp)
{
  ll res = 1;
  base %= mod;
  while (exp > 0)
  {
    if (exp % 2 == 1)
      res = (res * base) % mod;
    base = (base * base) % mod;
    exp /= 2;
  }
  return res;
}

ll modInverse(ll n)
{
  return power(n, mod - 2);
}

vector<ll> fact(60);
vector<ll> invFact(60);

void precompute()
{
  fact.at(0) = 1;
  invFact.at(0) = 1;
  for (int i = 1; i <= 55; i++)
  {
    fact.at(i) = (fact.at(i - 1) * i) % mod;
    invFact.at(i) = modInverse(fact.at(i));
  }
}

ll nCr(int n, int r)
{
  if (r < 0 || r > n)
    return 0;
  return fact.at(n) * invFact.at(r) % mod * invFact.at(n - r) % mod;
}

int main()
{
  fast_io;
  int T;
  cin >> T;
  precompute();
  while (T--)
  {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    ll sumTotal = 0;

    for (int i = 0; i <= n; i++)
    {
      cin >> a.at(i);
      sumTotal += a.at(i);
    }

    ll k = sumTotal / n;
    int r = sumTotal % n;

    ll dmdSum = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    for (int i = 1; i <= n; i++)
    {
      ll dmdK = k - a.at(i) > 0 ? k - a.at(i) : 0;
      dmdSum += dmdK;

      if (a.at(i) <= k)
      {
        cnt1++;
      }
      else
      {
        cnt2++;
      }
    }

    ll max_x = a.at(0) - dmdSum;

    if (max_x < 0)
    {
      cout << 0 << endl;
      continue;
    }

    ll ans = 0;

    for (int x = 0; x <= cnt1; x++)
    {
      int y = r - x;

      if (y < 0)
        continue;
      if (y > cnt2)
        continue;

      if (x <= max_x)
      {
        ll ways = nCr(cnt1, x) * nCr(cnt2, y) % mod;
        ans = (ans + ways) % mod;
      }
    }

    ans = (ans * fact.at(r)) % mod;
    ans = (ans * fact.at(n - r)) % mod;

    cout << ans << endl;
  }

  return 0;
}