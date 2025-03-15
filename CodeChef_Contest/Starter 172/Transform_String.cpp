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
    string a, b;
    cin >> a >> b;

    int it_b = b.length() - 1;
    ll total_cost = 0;

    for (int i = a.length() - 1; i >= 0; i--)
    {
      if (it_b >= 0 && a.at(i) == b.at(it_b))
        it_b--;
      else
        total_cost += i + 1;
    }

    for (int i = a.length() - b.length() - 1; i > 0; i--)
    {
      total_cost -= i;
    }

    if (it_b >= 0)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << total_cost << endl;
    }
  }

  return 0;
}