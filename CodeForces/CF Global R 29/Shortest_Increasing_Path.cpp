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

    if (x < y)
      cout << 2 << endl;
    else if (y == 1)
      cout << -1 << endl;
    else if (x > y + 1)
      cout << 3 << endl;
    else
      cout << -1 << endl;
  }

  return 0;
}