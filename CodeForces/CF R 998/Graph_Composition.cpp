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
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    vector<vector<int>> matrix(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m1; i++)
    {
      int e1, e2;
      cin >> e1 >> e2;

      matrix.at(e1).at(e2) = 1;
      matrix.at(e2).at(e1) = 1;
    }

    int edge_present = 0;

    for (int i = 0; i < m2; i++)
    {
      int _e1, _e2;
      cin >> _e1 >> _e2;

      if (matrix.at(_e1).at(_e2) > 0)
      {
        edge_present++;
      }
    }

    cout << m1 + m2 - edge_present * 2 << endl;
  }

  return 0;
}