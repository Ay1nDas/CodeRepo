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
    int r, x, d, n;
    cin >> r >> x >> d >> n;

    string rounds;
    cin >> rounds;

    int ratedCnt = 0;
    for (int i = 0; i < n; i++)
    {
      if (rounds.at(i) == '2' && r < x)
      {
        r = max(r - d, 0);
        ratedCnt++;
      }
      else if (rounds.at(i) == '1')
      {
        r = max(r - d, 0);
        ratedCnt++;
      }
    }

    cout << ratedCnt << endl;
  }

  return 0;
}