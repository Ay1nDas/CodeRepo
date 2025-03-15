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
    int n, max_achieve;
    cin >> n;
    cin >> max_achieve;
    cout << 1 << " ";

    for (int i = 1; i < n; i++)
    {
      int achieve;
      cin >> achieve;

      if (achieve > max_achieve)
      {
        max_achieve = achieve;
        cout << 1 << " ";
      }
      else
      {
        cout << 0 << " ";
      }
    }
    cout << endl;
  }

  return 0;
}