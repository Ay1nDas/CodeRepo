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
    int l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

    int lr, br;
    bool isPossible = true;

    if (l1 < b1)
    {
      lr = b1 - l1;
      br = b1;
    }
    else if (l1 > b1)
    {
      lr = l1;
      br = l1 - b1;
    }
    else
    {
      isPossible = false;
    }

    if (l2 == lr)
    {
      br -= b2;
    }
    else if (b2 == br)
    {
      lr -= l2;
    }
    else
    {
      isPossible = false;
    }

    if (l3 == lr)
    {
      br -= b3;
    }
    else if (b3 == br)
    {
      lr -= l3;
    }
    else
    {
      isPossible = false;
    }

    if (lr != 0 && br != 0)
    {
      isPossible = false;
    }

    cout << (isPossible ? "YES" : "NO") << endl;
  }

  return 0;
}