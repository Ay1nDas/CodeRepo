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
    int n, k;
    cin >> n >> k;

    vector<int> prem(n);
    string bi;
    cin >> bi;

    int running = 1;
    int max_streak = 0;
    int streak = 0;
    bool isPoss = true;

    for (int i = 0; i < n; i++)
    {
      if (bi.at(i) == '1')
      {
        prem.at(i) = running++;
        if (i > 0 && bi.at(i - 1) == '1')
          streak++;
        else
        {
          streak = 1;
          max_streak = max(streak, max_streak);
        }
      }
      else
      {
        max_streak = max(streak, max_streak);
        streak = 0;
      }
    }

    max_streak = max(streak, max_streak);

    if (max_streak >= k)
    {
      cout << "NO" << endl;
      continue;
    }

    for (int i = 0; i < n; i++)
    {
      if (prem.at(i) == 0)
        prem.at(i) = running++;
    }

    cout << "YES" << endl;
    for (auto i : prem)
      cout << i << " ";
    cout << endl;
  }

  return 0;
}