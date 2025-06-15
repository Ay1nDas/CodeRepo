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
    int n, k = 0;
    cin >> n >> k;

    // if (n - k)
    //   cout << 0;
    // n--;
    // while (k > 1)
    // {
    //   cout << 1;
    //   k--;
    //   n--;
    // }
    // while (n > 1)
    // {
    //   cout << 0;
    //   n--;
    // }
    // if (k)
    //   cout << 1;

    // cout << endl;

    for (int i = 0; i < k; i++)
    {
      cout << 1;
    }
    for (int i = 0; i < n - k; i++)
    {
      cout << 0;
    }
    cout << endl;
  }

  return 0;
}