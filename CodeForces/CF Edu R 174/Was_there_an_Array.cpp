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

    bool isPossible = true;
    int cnt = 0;

    for (int i = 0; i < n - 2; i++)
    {
      int num;
      cin >> num;

      if (num == 1)
      {
        if (cnt == 1 && i != 1)
          isPossible = false;
        cnt = 0;
      }
      else
      {
        cnt++;
      }
    }

    cout << (isPossible ? "YES" : "NO") << endl;
  }

  return 0;
}