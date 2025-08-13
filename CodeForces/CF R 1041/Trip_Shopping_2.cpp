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
    vector<vector<int>> arr(n, vector<int>(2));

    for (int i = 0; i < n; i++)
      cin >> arr.at(i).at(0);
    for (int i = 0; i < n; i++)
      cin >> arr.at(i).at(1);

    ll diff = 0;
    for (int i = 0; i < n; i++)
    {
      if (arr.at(i).at(0) < arr.at(i).at(1))
      {
        int tmp = arr.at(i).at(0);
        arr.at(i).at(0) = arr.at(i).at(1);
        arr.at(i).at(1) = tmp;
      }

      diff += arr.at(i).at(0) - arr.at(i).at(1);
    }

    sort(arr.begin(), arr.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] > b[0]; });

    int min_diff = INT_MAX;
    for (int i = 0; i + 1 < n; i++)
    {
      if (arr.at(i).at(1) < arr.at(i + 1).at(0))
      {
        min_diff = 0;
        break;
      }

      int opt_val = arr.at(i).at(0) + arr.at(i).at(1) - arr.at(i + 1).at(0) - arr.at(i + 1).at(1);

      int curr_val = arr.at(i).at(0) - arr.at(i).at(1) + arr.at(i + 1).at(0) - arr.at(i + 1).at(1);

      if (opt_val - curr_val < min_diff)
        min_diff = opt_val - curr_val;
    }

    cout << diff + min_diff << endl;
  }

  return 0;
}