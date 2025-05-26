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
    int x, y, k;
    cin >> x >> y >> k;
    int pile = max(x, y);

    if (pile <= k)
    {
      cout << "Alice" << endl;
    }
    else if (max(min(x, y), pile - k) <= k)
    {
      cout << "Alice" << endl;
    }
    else
    {
      cout << "Bob" << endl;
    }
  }

  return 0;
}