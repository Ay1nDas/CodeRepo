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
    int n, a;
    cin >> n >> a;

    vector<int> v(n);
    for (auto &i : v)
    {
      cin >> i;
    }

    int smlPt = 0;
    int lrgPt = 0;

    for (int i = 0; i < n; i++)
    {
      if (v.at(i) < a)
      {
        smlPt++;
      }
      else if (v.at(i) > a)
      {
        lrgPt++;
      }
    }

    if (smlPt > lrgPt)
    {
      cout << a - 1 << endl;
    }
    else
    {
      cout << a + 1 << endl;
    }
  }

  return 0;
}