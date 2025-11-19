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
    int a, b, n;
    cin >> a >> b >> n;

    double val = static_cast<double>(a) / n;

    if (val >= b || b == a)
    {
      cout << 1 << endl;
    }
    else
    {
      cout << 2 << endl;
    }
  }

  return 0;
}