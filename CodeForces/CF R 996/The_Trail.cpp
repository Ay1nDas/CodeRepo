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
    ll n, m;
    cin >> n >> m;

    string direction;
    cin >> direction;

    vector<vector<ll>> grid(n, vector<ll>(m));
    vector<ll> row_sum(n);
    vector<ll> col_sum(m);
    ll max_alt = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> grid.at(i).at(j);

        row_sum.at(i) += grid.at(i).at(j);
        col_sum.at(j) += grid.at(i).at(j);

        // if (max_alt < row_sum.at(i))
        //   max_alt = row_sum.at(i);
        // if (max_alt < col_sum.at(j))
        //   max_alt = col_sum.at(j);
      }
    }
    // max_alt += max(n, m);
    // cout << "MAx: " << max_alt << endl;

    int i = 0, j = 0;

    for (char c : direction)
    {
      if (c == 'D')
      {
        grid.at(i).at(j) = max_alt - row_sum.at(i);
        row_sum.at(i) += grid.at(i).at(j);
        col_sum.at(j) += grid.at(i).at(j);
        i++;
      }
      else if (c == 'R')
      {
        grid.at(i).at(j) = max_alt - col_sum.at(j);
        row_sum.at(i) += grid.at(i).at(j);
        col_sum.at(j) += grid.at(i).at(j);
        j++;
      }
    }

    grid.at(n - 1).at(m - 1) = max_alt - row_sum.at(n - 1);

    // cout << "Soln: " << endl;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
        cout << grid.at(i).at(j) << " ";
      cout << endl;
    }
  }
  return 0;
}