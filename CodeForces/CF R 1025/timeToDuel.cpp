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

    int pre = -1;
    int zeroCnt = 0;
    cin >> pre;
    if (pre == 0)
      zeroCnt++;
    bool isLier = false;

    for (int i = 1; i < n; i++)
    {
      int verdict = -1;
      cin >> verdict;
      if (verdict == 0)
        zeroCnt++;

      if (verdict == pre && verdict == 0)
      {
        isLier = true;
      }
      pre = verdict;
    }

    if (zeroCnt == 0)
      isLier = true;

    cout << (isLier ? "YES" : "NO") << endl;
  }

  return 0;
}