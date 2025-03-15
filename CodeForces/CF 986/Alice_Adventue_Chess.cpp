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

    string path;
    cin >> path;

    long long x{0}, y{0};
    bool alice_reached = false;

    for (int i = 0; i < 20; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (path.at(j) == 'N')
          y++;
        else if (path.at(j) == 'S')
          y--;
        else if (path.at(j) == 'E')
          x++;
        else if (path.at(j) == 'W')
          x--;

        if (x == a && y == b)
        {
          alice_reached = true;
          break;
        }
      }
      if (alice_reached)
        break;
    }

    cout << (alice_reached ? "YES" : "NO") << endl;
  }

  return 0;
}