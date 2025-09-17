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

void fillGraph(vector<vector<int>> &graph, int i, int j, int id)
{
  graph.at(i).at(j) = id;

  if (i - 1 >= 0 && graph.at(i - 1).at(j) == -1)
    fillGraph(graph, i - 1, j, id);
  if (i + 1 < graph.size() && graph.at(i + 1).at(j) == -1)
    fillGraph(graph, i + 1, j, id);

  if (j - 1 >= 0 && graph.at(i).at(j - 1) == -1)
    fillGraph(graph, i, j - 1, id);
  if (j + 1 < graph.at(0).size() && graph.at(i).at(j + 1) == -1)
    fillGraph(graph, i, j + 1, id);
}

int main()
{

  fast_io;
  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n, vector<int>(m));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      char c;
      cin >> c;
      graph.at(i).at(j) = (c == '.' ? -1 : -2);
    }
  }

  int roomCnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (graph.at(i).at(j) == -1)
        fillGraph(graph, i, j, ++roomCnt);
    }
  }

  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < m; j++)
  //   {
  //     cout << graph.at(i).at(j) << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  cout << roomCnt << endl;

  return 0;
}