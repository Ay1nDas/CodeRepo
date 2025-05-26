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
    int n, x;
    cin >> n >> x;

    vector<int> bits(n + 1, 1);
    unordered_map<int, int> mapped;

    for (int i = 1; i <= n; i++)
    {
      int p = x ^ i;
      if (p <= n && (p | i) == x)
      {
        mapped[i] = p;
      }
    }

    for (int i = 1; i <= n; i++)
    {
      cout << (mapped[i] ? mapped[i] : i) << " ";
    }
    cout << endl;
  }
  return 0;
}