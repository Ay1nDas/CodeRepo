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
  int n, m;
  cin >> n >> m;

  vector<int> arr(n + 1);
  for (int i = 1; i < n + 1; i++)
    cin >> arr.at(i);

  vector<vector<ll>> grid(n + 1, vector<ll>(m + 2));
  for (int i = 0; i < m + 2; i += 3)
    grid.at(0).at(i) = 1;

  for (int i = 1; i < n + 1; i++)
  {
    if (arr.at(i) != 0)
    {
      int idx = arr.at(i);
      grid.at(i).at(arr.at(i)) = (grid.at(i - 1).at(idx - 1) + grid.at(i - 1).at(idx) + grid.at(i - 1).at(idx + 1)) % mod;
    }
    else
    {
      for (int j = 1; j < m + 1; j++)
      {
        grid.at(i).at(j) = (grid.at(i - 1).at(j - 1) + grid.at(i - 1).at(j) + grid.at(i - 1).at(j + 1)) % mod;
      }
    }
  }

  ll result = 0;
  for (int i = 1; i < m + 1; i++)
    result = (result + grid.at(n).at(i)) % mod;

  cout << result << endl;
  return 0;
}