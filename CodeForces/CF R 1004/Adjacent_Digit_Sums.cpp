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
    int x, y;
    cin >> x >> y;

    // if (y - x == 1)
    // {
    //   cout << "YES" << endl;
    // }
    // else
    if ((x - y + 1) >= 0 && (x - y + 1) % 9 == 0)
    {
      cout << "YES" << endl;
    }
    // else if (y == 1 && x % 9 == 0)
    // {
    //   cout << "YES" << endl;
    // }
    else
    {
      cout << "NO" << endl;
    }
  }

  return 0;
}