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
    int n, x;
    cin >> n >> x;

    string space;
    cin >> space;

    if (x == 1 || x == n)
    {
      cout << 1 << endl;
      continue;
    }

    int lw = 0, uw = n + 1;
    for (int i = x - 1; i >= 0; i--)
    {
      if (space.at(i) == '#')
      {
        lw = i + 1;
        break;
      }
    }
    for (int i = x - 1; i < space.length(); i++)
    {
      if (space.at(i) == '#')
      {
        uw = i + 1;
        break;
      }
    }

    if (lw < (n + 1) - uw)
      lw = x - 1;
    else
      uw = x + 1;
    // cout << "WALLS: " << lw << " " << uw << endl;
    // cout << "Walls: " << lw << " " << uw << endl;
    int days = min(lw, (n + 1) - uw);
    cout << days + 1 << endl;
  }

  return 0;
}