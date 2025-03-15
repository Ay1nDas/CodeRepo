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
    string bi;
    cin >> n >> bi;
    int cnt = 1;

    for (int i = 1; i < n; i++)
    {
      if (bi.at(i) != bi.at(i - 1))
      {
        cnt++;
      }
    }

    if (bi.at(0) == '0')
    {
      cout << cnt - 1 << endl;
    }
    else
    {
      cout << cnt << endl;
    }
  }

  return 0;
}