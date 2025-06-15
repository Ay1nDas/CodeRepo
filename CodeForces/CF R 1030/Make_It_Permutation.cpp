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
    int n = 0;
    cin >> n;

    cout << n * 2 - 1 << endl;
    cout << 1 << " " << 1 << " " << n << endl;
    int idx = n - 1;
    for (int i = 2; i <= n; i++)
    {
      cout << i << " " << 1 << " " << idx << endl;
      cout << i << " " << idx + 1 << " " << n << endl;
      idx--;
    }
  }

  return 0;
}