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
    ll n, m, a, b;
    cin >> n >> m >> a >> b;

    if (gcd(a, n) == 1 && gcd(b, m) == 1 && gcd(n, m) < 3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
  }

  return 0;
}