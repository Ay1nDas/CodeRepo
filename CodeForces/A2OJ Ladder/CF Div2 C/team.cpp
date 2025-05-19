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
  int n, m;
  cin >> n >> m;

  if (n == m + 1)
  {
    while (m > 0)
    {
      cout << "01";
      m--;
      n--;
    }
    cout << 0 << endl;
  }
  else if (n > m)
  {
    cout << -1 << endl;
  }
  else if (m <= 2 * n + 2)
  {
    while (m > n && n > 0)
    {
      cout << 110;
      m -= 2;
      n--;
    }

    while (n > 0)
    {
      cout << 10;
      n--;
      m--;
    }
    while (m > 0)
    {
      cout << 1;
      m--;
    }
    cout << endl;
  }
  else
  {
    cout << -1 << endl;
  }

  return 0;
}