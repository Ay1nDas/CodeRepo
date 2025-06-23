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
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> grid(n, vector<int>(m));
    int total_gold = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        char val;
        cin >> val;

        switch (val)
        {
        case 'g':
          grid.at(i).at(j) = 1;
          total_gold++;
          break;
        case '.':
          grid.at(i).at(j) = 0;
          break;
        case '#':
          grid.at(i).at(j) = -1;
          break;
        }
      }
    }

    int min_blast = 0;
    for (int i = 0; i < k - 1; i++)
    {
      for (int j = 0; j < k - 1; j++)
      {
        if (grid.at(i).at(j) == 0)
          min_blast++;
      }
    }

    int i = 0, j = 0;
    int blast_gold = min_blast;
    while (i < n && j < m)
    {
      while (j < m)
      {
        j++;

        if (j + k - 1 < m)
        {
          for (int a = max(0, i - k + 1); a <= min(n, i + k - 1); a++)
            if (grid.at(a).at(j + k - 1) == 0)
              blast_gold++;
        }
        if (j - k >= 0)
        {
          for (int a = max(0, i - k + 1); a <= min(n, i + k - 1); a++)
            if (grid.at(a).at(j - k) == 0)
              blast_gold--;
        }

        if (min_blast > blast_gold)
          min_blast = blast_gold;
      }

      if (j < n)
      {
        j++;
      }
      else
      {
        break;
      }
    }

    cout << total_gold - min_blast << endl;
  }

  return 0;
}