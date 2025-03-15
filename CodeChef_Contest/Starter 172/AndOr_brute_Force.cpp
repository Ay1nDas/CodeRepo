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
    int n;
    cin >> n;
    vector<int> bi_arr(n);
    for (int i = 0; i < n; i++)
    {
      cin >> bi_arr.at(i);
    }

    int q;
    cin >> q;

    while (q--)
    {
      int p, x;
      cin >> p >> x;

      bi_arr.at(p - 1) = x;
      int res = bi_arr.at(0);

      for (int i = 1; i < n; i++)
      {
        if (i % 2 == 1)
        {
          res = res & bi_arr.at(i);
        }
        else if (i % 2 == 0)
        {
          res = res | bi_arr.at(i);
        }
      }
      cout << res << endl;
    }
  }

  return 0;
}