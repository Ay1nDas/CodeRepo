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

  // fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> maze(n, vector<char>(m));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        cin >> maze.at(i).at(j);

    vector<vector<int>> route(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        vector<array<int, 2>> stack;
        int i_route = i;
        int j_route = j;

        if (maze.at(i).at(j) == '?')
          continue;

        while (route.at(i_route).at(j_route) == 0)
        {

          route.at(i_route).at(j_route) = 2;
          stack.push_back({i_route, j_route});

          switch (maze.at(i_route).at(j_route))
          {
          case 'U':
            i_route--;
            break;
          case 'D':
            i_route++;
            break;
          case 'L':
            j_route--;
            break;
          case 'R':
            j_route++;
            break;
          case '?':
            route.at(i_route).at(j_route) = -1;
          }

          if (!(i_route > 0 && i_route < n && j_route > 0 && j_route < m) || route.at(i_route).at(j_route) == 1)
          {
            for (auto arr : stack)
              route.at(arr[0]).at(arr[1]) = 1;
            break;
          }
          else if (route.at(i_route).at(j_route) == 2)
          {
            for (auto arr : stack)
              route.at(arr[0]).at(arr[1]) = -1;
            break;
          }
          else if (route.at(i_route).at(j_route) == -1)
          {
            for (auto arr : stack)
              route.at(arr[0]).at(arr[1]) = -1;
            break;
          }
        }
      }
    }

    int count{0};

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (route.at(i).at(j) == 0)
        {
          if (i + 1 < n && (route.at(i + 1).at(j) == -1 || route.at(i + 1).at(j) == 0))
          {
            route.at(i).at(j) = -1;
            count++;
          }

          else if (i - 1 > 0 && (route.at(i - 1).at(j) == -1 || route.at(i - 1).at(j) == 0))
          {
            route.at(i).at(j) = -1;
            count++;
          }

          else if (j + 1 < m && (route.at(i).at(j + 1) == -1 || route.at(i).at(j + 1) == 0))
          {
            route.at(i).at(j) = -1;
            count++;
          }

          else if (j - 1 > 0 && (route.at(i).at(j - 1) == -1 || route.at(i).at(j - 1) == 0))
          {
            route.at(i).at(j) = -1;
            count++;
          }
        }
        else if (route.at(i).at(j) == -1)
        {
          count++;
        }
      }
    }

    // for (auto vec : route)
    // {
    //   for (auto i : vec)
    //   {
    //     cout << i;
    //   }
    //   cout << endl;
    // }

    std::cout << count << endl;
  }

  return 0;
}