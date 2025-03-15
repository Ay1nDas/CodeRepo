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
    int n, m, b;
    cin >> n >> m;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
      cin >> a.at(i);
    cin >> b;

    bool isPossible = true;
    for (int i = 0; i + 1 < n; i++)
    {
      if (a.at(i) > a.at(i + 1))
      {
        if (i == 0 || a.at(i - 1) <= b - a.at(i))
        {
          a.at(i) = b - a.at(i);
        }
        if (i + 2 == n || b - a.at(i + 1) <= a.at(i + 2))
        {
          a.at(i + 1) = b - a.at(i + 1);
        }

        if (a.at(i) > a.at(i + 1))
        {
          isPossible = false;
          break;
        }
      }
    }

    cout << (isPossible ? "YES" : "NO") << endl;
  }

  return 0;
}