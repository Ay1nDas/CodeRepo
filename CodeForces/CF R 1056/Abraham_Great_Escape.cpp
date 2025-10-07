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
    int n, k;
    cin >> n >> k;

    if (n * n - k == 1)
    {
      cout << "NO" << endl;
      continue;
    }

    vector<vector<char>> maze(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
      if (k != 0)
      {
        for (int j = 0; j < n; j++)
        {
          if (k != 0)
          {
            maze.at(i).at(j) = 'U';
            k--;
          }
          else if (j != n - 1)
          {
            maze.at(i).at(j) = 'R';
          }
          else if (maze.at(i).at(j - 1) == 'R')
          {
            maze.at(i).at(j) = 'L';
          }
          else
          {
            maze.at(i).at(j) = 'D';
          }
        }
      }
      else
      {
        maze.at(i).at(0) = 'R';
        for (int j = 1; j < n; j++)
        {
          maze.at(i).at(j) = 'L';
        }
      }
    }

    cout << "YES" << endl;
    for (auto vec : maze)
    {
      for (auto c : vec)
      {
        cout << c;
      }
      cout << endl;
    }
  }

  return 0;
}