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
    int n, s;
    cin >> n >> s;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
      int dx, dy, x, y;
      cin >> dx >> dy >> x >> y;

      if (dx == dy && x == y)
        cnt++;
      else if (dx == -dy && x + y == s)
        cnt++;
    }

    cout << cnt << endl;
  }

  return 0;
}