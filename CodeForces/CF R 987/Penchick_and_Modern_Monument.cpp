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

    int max_streak{1}, streak{1};
    int pre_length{0};
    cin >> pre_length;

    for (int i = 1; i < n; i++)
    {
      int length{0};
      cin >> length;

      if (length == pre_length)
      {
        streak++;
      }
      else
      {
        if (streak > max_streak)
          max_streak = streak;
        streak = 1;
      }
      pre_length = length;
    }
    if (streak > max_streak)
      max_streak = streak;

    cout << n - max_streak << endl;
  }

  return 0;
}