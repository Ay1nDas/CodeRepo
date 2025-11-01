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

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, 1, -1};

bool isValid(int r, int c, int n)
{
  return r >= 0 && r < n && c >= 0 && c < n;
}

bool solve()
{
  int n;
  cin >> n;
  vector<string> grid(n);
  vector<pair<int, int>> initBlack;
  for (int i = 0; i < n; ++i)
  {
    cin >> grid[i];
    for (int j = 0; j < n; ++j)
    {
      if (grid[i][j] == '#')
      {
        initBlack.push_back({i, j});
      }
    }
  }

  if (initBlack.empty())
  {
    return true;
  }

  for (int r = 0; r < n; ++r)
  {
    for (int c = 0; c < n; ++c)
    {
      if (grid[r][c] == '#')
      {
        if (c + 2 < n && grid[r][c + 1] == '#' && grid[r][c + 2] == '#')
          return false;
        if (r + 2 < n && grid[r + 1][c] == '#' && grid[r + 2][c] == '#')
          return false;
      }
    }
  }

  vector<vector<bool>> mustWhite(n, vector<bool>(n, false));
  for (int r = 0; r < n; ++r)
  {
    for (int c = 0; c < n; ++c)
    {
      if (grid[r][c] == '.')
      {
        if (isValid(r, c - 1, n) && isValid(r, c - 2, n) && grid[r][c - 1] == '#' && grid[r][c - 2] == '#')
          mustWhite[r][c] = true;
        if (isValid(r, c + 1, n) && isValid(r, c + 2, n) && grid[r][c + 1] == '#' && grid[r][c + 2] == '#')
          mustWhite[r][c] = true;
        if (isValid(r, c - 1, n) && isValid(r, c + 1, n) && grid[r][c - 1] == '#' && grid[r][c + 1] == '#')
          mustWhite[r][c] = true;
        if (isValid(r - 1, c, n) && isValid(r - 2, c, n) && grid[r - 1][c] == '#' && grid[r - 2][c] == '#')
          mustWhite[r][c] = true;
        if (isValid(r + 1, c, n) && isValid(r + 2, c, n) && grid[r + 1][c] == '#' && grid[r + 2][c] == '#')
          mustWhite[r][c] = true;
        if (isValid(r - 1, c, n) && isValid(r + 1, c, n) && grid[r - 1][c] == '#' && grid[r + 1][c] == '#')
          mustWhite[r][c] = true;
      }
    }
  }

  set<pair<int, int>> foundBlack;
  vector<vector<vector<vector<bool>>>> visited(n, vector<vector<vector<bool>>>(n, vector<vector<bool>>(2, vector<bool>(3, false))));
  queue<tuple<int, int, int, int>> q;

  pair<int, int> startNode = initBlack[0];
  foundBlack.insert(startNode);

  q.push({startNode.first, startNode.second, 0, 1});
  q.push({startNode.first, startNode.second, 1, 1});
  visited[startNode.first][startNode.second][0][1] = true;
  visited[startNode.first][startNode.second][1][1] = true;

  while (!q.empty())
  {
    auto [r, c, dir, len] = q.front();
    q.pop();

    for (int i = 0; i < 4; ++i)
    {
      int nr = r + dr[i];
      int nc = c + dc[i];

      if (!isValid(nr, nc, n))
        continue;

      if (grid[nr][nc] == '.' && mustWhite[nr][nc])
        continue;

      if (grid[nr][nc] == '#' || grid[nr][nc] == '.')
      {

        int moveDir = (dr[i] != 0) ? 1 : 0;
        int newLen;

        if (moveDir == dir)
        {
          newLen = len + 1;
        }
        else
        {
          newLen = 1;
        }

        if (newLen > 2)
          continue;

        if (!visited[nr][nc][moveDir][newLen])
        {
          visited[nr][nc][moveDir][newLen] = true;
          q.push({nr, nc, moveDir, newLen});
          if (grid[nr][nc] == '#')
          {
            foundBlack.insert({nr, nc});
          }
        }
      }
    }
  }

  return foundBlack.size() == initBlack.size();
}

int main()
{

  fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    if (solve())
    {
      cout << "YES\n";
    }
    else
    {
      cout << "NO\n";
    }
  }

  return 0;
}
