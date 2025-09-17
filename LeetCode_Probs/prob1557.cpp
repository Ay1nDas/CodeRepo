#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs(int n, vector<vector<int>> &graph, unordered_map<int, int> &reqd_vertices, int node)
  {
    for (auto i : graph.at(node))
    {
      if (reqd_vertices[i] == 0)
      {
        reqd_vertices[i] = 1;
        dfs(n, graph, reqd_vertices, i);
      }
    }
  }

  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
  {
    vector<vector<int>> graph(n);
    for (auto e : edges)
      graph.at(e.at(0)).push_back(e.at(1));

    unordered_map<int, int> reqd_vertices;

    for (int i = 0; i < n; i++)
    {
      if (reqd_vertices[i] == 0)
        dfs(n, graph, reqd_vertices, i);
    }

    vector<int> res;
    for (int i = 0; i < n; i++)
    {
      if (reqd_vertices[i] == 0)
        res.push_back(i);
    }

    return res;
  }
};

int main()
{
  return 0;
}