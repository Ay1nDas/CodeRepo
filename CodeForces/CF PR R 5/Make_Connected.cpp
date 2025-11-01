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

bool dfsPathFind(vector<vector<char>> &grid, int i, int j)
{
  cout << i << " " << j << endl;
  if (i < 0 || j < 0)
  {
    return false;
  }
  else if (i >= grid.size() || j >= grid.at(0).size())
  {
    return false;
  }
  else if (grid.at(i).at(j) == '0')
  {
    return false;
  }
  else if ((!(i > 0) || (grid.at(i - 1).at(j) == '#' || grid.at(i - 1).at(j) == '0')) && (!(i < grid.size() - 1) || (grid.at(i + 1).at(j) == '#' || grid.at(i + 1).at(j) == '0')))
  {
    return false;
  }
  else if ((!(j > 0) || (grid.at(i).at(j - 1) == '#' || grid.at(i).at(j - 1) == '0')) && (!(j < grid.at(0).size() - 1) || (grid.at(i).at(j + 1) == '#' || grid.at(i).at(j + 1) == '0')))
  {
    return false;
  }
  else if (grid.at(i).at(j) == '#')
  {
    return true;
  }

  grid.at(i).at(j) = '0';
  bool found = false;

  if (!found)
  {
    found = dfsPathFind(grid, i - 1, j);
  }
  if (!found)
  {
    found = dfsPathFind(grid, i, j - 1);
  }
  if (!found)
  {
    found = dfsPathFind(grid, i + 1, j);
  }
  if (!found)
  {
    found = dfsPathFind(grid, i, j + 1);
  }

  if (found)
  {
    grid.at(i).at(j) = '#';
  }

  return found;
}

int main()
{

  fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> grid.at(i).at(j);
      }
    }

    bool isPoss = true;
    for (int i = 1; i < n - 1 && isPoss; i++)
    {
      for (int j = 1; j < n - 1; j++)
      {
        if (grid.at(i).at(j) == '.')
        {
          continue;
        }
        if (grid.at(i - 1).at(j) == '#' && grid.at(i + 1).at(j) == '#')
        {
          isPoss = false;
          break;
        }
        if (grid.at(i).at(j - 1) == '#' && grid.at(i).at(j + 1) == '#')
        {
          isPoss = false;
          break;
        }
      }
    }

    if (!isPoss)
    {
      cout << "NO" << endl;
      continue;
    }

    bool connected = true;
    for (int i = 0; i < n && connected; i++)
    {
      for (int j = 0; j < n && connected; j++)
      {
        if (grid.at(i).at(j) == '#')
        {
          connected = dfsPathFind(grid, i - 1, j);
          connected = dfsPathFind(grid, i + 1, j);
          connected = dfsPathFind(grid, i, j - 1);
          connected = dfsPathFind(grid, i, j + 1);
        }
      }
    }

    cout << (connected ? "YES" : "NO") << endl;
  }

  return 0;
}