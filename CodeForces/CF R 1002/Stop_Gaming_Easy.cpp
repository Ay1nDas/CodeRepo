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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> a.at(i).at(j);

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> b.at(i).at(j);

    int ai = 0, aj = 0;
    // int bi = 0, bj = 0;
    int opps = 0;

    for (int i = 0; i < n; i++)
    {
      for (int bj = 0; bj < m; bj++)
      {
        if ((a.at(i).begin(), a.at(i).begin() + m - bj - 1) == (b.at(i).begin() + bj, a.at(i).end()))
        {
        }
      }
    }
  }

  return 0;
}