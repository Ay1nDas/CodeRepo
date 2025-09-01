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
    int n, a, b;
    cin >> n >> a >> b;

    if (a > b)
    {
      if (n % 2 == a % 2 && a % 2 == b % 2)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
    else
    {
      if (n % 2 == b % 2)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }

  return 0;
}