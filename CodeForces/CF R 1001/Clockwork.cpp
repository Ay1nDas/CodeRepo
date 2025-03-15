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
    // int min_time = n * 2 - 2;
    bool isInfinite = true;

    for (int i = 0; i < n; i++)
    {
      int num;
      cin >> num;

      int left_time = (i + 1) * 2 - 2;
      int right_time = (n - i) * 2 - 2;
      int min_time = max(left_time, right_time);

      if (num <= min_time)
        isInfinite = false;
    }
    cout << (isInfinite ? "YES" : "NO") << endl;
  }

  return 0;
}