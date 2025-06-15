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
    int x;
    cin >> x;

    int a = 0, b = 0, c = 0;
    int cnt = 0;

    while (a < x || b < x || c < x)
    {
      if (a < x)
      {
        int max = min(b, c) * 2 + 1;
        a = (max < x) ? max : x;
        cnt++;
      }
      // cout << a << " " << b << " " << c << endl;

      if (b < x)
      {
        int max = min(a, c) * 2 + 1;
        b = (max < x) ? max : x;
        cnt++;
      }
      // cout << a << " " << b << " " << c << endl;

      if (c < x)
      {
        int max = min(b, a) * 2 + 1;
        c = (max < x) ? max : x;
        cnt++;
      }
      // cout << a << " " << b << " " << c << endl;
    }
    cout << cnt << endl;
  }

  return 0;
}