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
    vector<ll> arr(n);

    for (int i = 0; i < n; i++)
      cin >> arr.at(i);

    ll min_cost = LONG_LONG_MAX;

    for (int i = 0; i < n; i++)
    {
      ll tot_cost = 0;
      tot_cost += i * arr.at(i);

      while (i + 1 < n && arr.at(i) == arr.at(i + 1))
        i++;
      tot_cost += (n - i - 1) * arr.at(i);

      min_cost = min(min_cost, tot_cost);
    }
    cout << min_cost << endl;
  }

  return 0;
}