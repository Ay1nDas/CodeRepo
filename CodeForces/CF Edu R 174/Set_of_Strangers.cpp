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
    vector<vector<int>> matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> matrix.at(i).at(j);
      }
    }

    // cout << "HERE!" << endl;

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        int ele = matrix.at(i).at(j);
        if (freq[ele] == 2)
          continue;

        if (i - 1 >= 0 && ele == matrix.at(i - 1).at(j))
        {
          freq[ele] = 2;
          continue;
        }

        if (i + 1 < n && ele == matrix.at(i + 1).at(j))
        {
          freq[ele] = 2;
          continue;
        }

        if (j - 1 >= 0 && ele == matrix.at(i).at(j - 1))
        {
          freq[ele] = 2;
          continue;
        }

        if (j + 1 < m && ele == matrix.at(i).at(j + 1))
        {
          freq[ele] = 2;
          continue;
        }

        freq[ele] = 1;
      }
    }

    int total_val = 0;
    int sub = 0;
    for (auto it = freq.begin(); it != freq.end(); it++)
    {
      total_val += it->second;
      sub = max(sub, it->second);
    }

    cout << total_val - sub << endl;
  }

  return 0;
}