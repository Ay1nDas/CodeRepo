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

    string str;
    cin >> str;

    int actual_diff = 0;
    for (auto c : str)
    {
      if (c == 'a')
        actual_diff++;
      else
        actual_diff--;
    }

    if (actual_diff == 0)
    {
      cout << 0 << endl;
      continue;
    }

    unordered_map<int, int> diff;
    diff[0] = -1;
    int min_len = n;
    int curr_diff = 0;
    for (int i = 0; i < n; i++)
    {
      if (str.at(i) == 'a')
        curr_diff++;
      else
        curr_diff--;

      int tgt_diff = curr_diff - actual_diff;

      if (diff.count(tgt_diff))
      {
        int pre = diff[tgt_diff];
        min_len = min(min_len, i - pre);
      }

      diff[curr_diff] = i;
    }

    // cout << "ANS: ";
    if (min_len == n)
      cout << -1 << endl;
    else
      cout << min_len << endl;
  }

  return 0;
}