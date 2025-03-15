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

    // vector<int> arr(n);
    int odd = 0, even = 0;
    for (int i = 0; i < n; i++)
    {
      int num;
      cin >> num;
      if (num % 2 == 0)
      {
        even++;
      }
      else
      {
        odd++;
      }
    }

    if (even)
    {
      cout << odd + 1 << endl;
    }
    else
    {
      cout << odd - 1 << endl;
    }
  }

  return 0;
}