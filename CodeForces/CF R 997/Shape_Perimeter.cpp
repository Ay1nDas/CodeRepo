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
    int n, m;
    cin >> n >> m;

    int total_perm = m * 4 * n;
    int garb_x, garb_y;
    cin >> garb_x >> garb_y;
    n--;
    // int coords_x = 0, coords_y = 0;

    while (n--)
    {
      int x, y;
      cin >> x >> y;
      total_perm -= 2 * (2 * m - x - y);
    }

    cout << total_perm << endl;
  }

  return 0;
}