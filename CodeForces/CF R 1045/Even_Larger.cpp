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

    for (int i = 0; i < n; i++)
      cin >> arr.at(i);

    ll ops = 0;
    for (int i = 1; i + 1 < n; i += 2) // Add condition for last one.
    {
      int min_idx, max_idx;
      if (arr.at(i - 1) > arr.at(i + 1))
      {
        min_idx = i + 1;
        max_idx = i - 1;
      }
      else
      {
        min_idx = i - 1;
        max_idx = i + 1;
      }

      if (arr.at(i) < arr.at(min_idx))
      {
        ops += arr.at(min_idx) + arr.at(max_idx) - 2 * arr.at(i);
        arr.at(min_idx) = arr.at(max_idx) = arr.at(i);
      }
      else if (arr.at(i) < arr.at(max_idx))
      {
        ops += arr.at(max_idx) - arr.at(i);
        arr.at(max_idx) = arr.at(i);
      }

      if (arr.at(i) < arr.at(i - 1) + arr.at(i + 1))
      {
        int diff = arr.at(i - 1) + arr.at(i + 1) - arr.at(i);
        ops += diff;
        arr.at(i + 1) -= diff;
      }
    }

    if (n % 2 == 0)
    {
      if (arr.at(n - 2) > arr.at(n - 1))
      {
        ops += arr.at(n - 2) - arr.at(n - 1);
        arr.at(n - 2) = arr.at(n - 1);
      }
    }

    cout << ops << endl;
  }

  return 0;
}