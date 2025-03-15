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

    int odd_left = x % 2;
    x -= odd_left;

    for (int i = 0; i < x / 2; i++)
      cout << 1;
    for (int i = 0; i < y / 2; i++)
      cout << 2;

    for (int i = 0; i < odd_left; i++)
      cout << 1;

    for (int i = y / 2; i < y; i++)
      cout << 2;
    for (int i = 0; i < x / 2; i++)
      cout << 1;
    cout << endl;
  }

  return 0;
}