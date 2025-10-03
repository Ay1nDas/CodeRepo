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
  int n;
  cin >> n;

  vector<string> grid(n);
  for (int i = 0; i < n; i++)
    cin >> grid.at(i);

  vector<vector<int>> paths(n + 1, vector<int>(n + 1));
  paths.at(n - 1).at(n) = 1;

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = n - 1; j >= 0; j--)
    {
      if (grid.at(i).at(j) == '*')
        continue;

      paths.at(i).at(j) = (paths.at(i).at(j + 1) + paths.at(i + 1).at(j)) % mod;
    }
  }

  cout << paths.at(0).at(0) << endl;

  return 0;
}