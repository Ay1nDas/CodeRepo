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

    vector<int> columns(n);
    ll sum_columns{0};

    for (int i = 0; i < n; i++)
    {
      cin >> columns.at(i);
      sum_columns += columns.at(i);
    }

    sort(columns.rbegin(), columns.rend());
    ll max_len = (sum_columns + x) / n;
    do
    {
      ll water_used = n * max_len - sum_columns;

      for (int i = 0; i < n && columns.at(i) > max_len; i++)
        water_used += columns.at(i) - max_len;

      if (water_used <= x)
        break;
      else if (water_used - x > n)
        max_len -= (water_used - x) / n - 1;

    } while (max_len--);

    cout << max_len << endl;
  }

  return 0;
}