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

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
      cin >> arr.at(i);

    int max_streak = 0;

    for (int i = 0; i < n; i++)
    {
      int curr_num = arr.at(i) * x;
      int streak = 1;

      int pre_num = curr_num;
      for (int j = i - 1; j >= 0; j--)
      {
        if (pre_num >= arr.at(j))
          streak++;
        else
          break;
        pre_num = arr.at(j);
      }

      pre_num = curr_num;
      for (int j = i + 1; j < n; j++)
      {
        if (pre_num <= arr.at(j))
          streak++;
        else
          break;
        pre_num = arr.at(j);
      }

      if (streak > max_streak)
      {
        // cout << "At: " << arr.at(i) << "is: " << streak << endl;
        max_streak = streak;
      }
    }

    cout << max_streak << endl;
  }

  return 0;
}