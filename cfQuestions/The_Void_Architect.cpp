#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
    ll rod_factor = n / k;
    ll comb_rod = rod_factor * k;

    // cout << rod_factor << " " << comb_rod << endl;

    ll x_count = ((((n % mod) * (n % mod)) % mod) * (rod_factor % mod)) % mod;
    ll y_count = (((((n - comb_rod) % mod) * (n % mod)) % mod) * (rod_factor % mod)) % mod;
    ll z_count = (((((n - comb_rod) % mod) * ((n - comb_rod) % mod)) % mod) * (rod_factor % mod)) % mod;

    cout << ((x_count + y_count) % mod + z_count) % mod << endl;
  }

  return 0;
}