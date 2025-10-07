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

    vector<int> arr(n);
    for (auto &a : arr)
      cin >> a;

    int pre_x = 0;
    int x_total = 0;
    int total_poss = 0;
    for (int i = 1; i < n; i++)
    {
      int curr_x = arr.at(i) - arr.at(i - 1) + 1 - pre_x;
      // cout << curr_x << endl;

      if (curr_x != 0 && curr_x != 1)
      {
        x_total = -1;
        break;
      }
      else
      {
        x_total += curr_x;
        pre_x = curr_x;
      }
    }
    if (arr.at(0) == n - x_total)
      total_poss++;

    pre_x = 1;
    x_total = 1;

    for (int i = 1; i < n; i++)
    {
      int curr_x = arr.at(i) - arr.at(i - 1) + 1 - pre_x;
      // cout << curr_x << endl;

      if (curr_x != 0 && curr_x != 1)
      {
        x_total = -1;
        break;
      }
      else
      {
        x_total += curr_x;
        pre_x = curr_x;
      }
    }
    if (arr.at(0) == 1 + n - x_total)
      total_poss++;

    cout << total_poss << endl;
  }

  return 0;
}