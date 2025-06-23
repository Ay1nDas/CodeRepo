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
    int w, h, a, b;
    cin >> w >> h >> a >> b;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x_gap = abs(x1 - x2) - a;
    int y_gap = abs(y1 - y2) - b;

    // bool isPossible = true;

    // if (x_gap >= 0 && y_gap >= 0)
    // {
    //   cout << "YES" << endl;
    // }
    // else if (x_gap >= 0)
    // {
    //   if (x_gap % a == 0)
    //     cout << "YES" << endl;
    //   else
    //     cout << "NO" << endl;
    // }
    // else if (y_gap >= 0)
    // {
    //   if (y_gap % b == 0)
    //     cout << "YES" << endl;
    //   else
    //     cout << "NO" << endl;
    // }
    // else
    // {
    //   cout << "ERROR" << endl;
    // }

    if (x_gap == 0 || y_gap == 0)
      cout << "YES" << endl;
    else if ((x_gap > 0 && x_gap % a == 0) || (y_gap > 0 && y_gap % b == 0))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}