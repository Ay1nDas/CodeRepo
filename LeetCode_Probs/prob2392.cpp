#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool dfs(int v, const vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &inStack)
  {
    visited[v] = true;
    inStack[v] = true;

    int n = graph.size();
    for (int u = 0; u < n; u++)
    {
      if (graph[v][u])
      {
        if (!visited[u] && dfs(u, graph, visited, inStack))
          return true;
        else if (inStack[u])
          return true;
      }
    }

    inStack[v] = false;
    return false;
  }

  bool hasCycle(const vector<vector<int>> &graph)
  {
    int n = graph.size();
    vector<bool> visited(n, false), inStack(n, false);

    for (int i = 0; i < n; i++)
    {
      if (!visited[i] && dfs(i, graph, visited, inStack))
        return true;
    }
    return false;
  }

  void bfs(vector<vector<int>> &graph, vector<int> &levels, int k)
  {
    for (int i = 1; i < graph.size(); i++)
    {
      queue<int> q;
      q.push(i);
      int curr_lvl = 0;

      while (q.size() > 0)
      {
        int cnt = q.size();
        while (cnt--)
        {
          int node = q.front();
          q.pop();
          if (levels.at(node) <= curr_lvl)
            levels.at(node) = curr_lvl;
          else
            continue;

          for (int i = 1; i <= k; i++)
          {
            if (graph.at(node).at(i) != 0)
              q.push(i);
          }
        }
        curr_lvl++;
      }
    }
  }

  vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
  {
    vector<vector<int>> rowGraph(k + 1, vector<int>(k + 1));

    for (auto v : rowConditions)
      rowGraph.at(v.at(0)).at(v.at(1)) = 1;

    if (hasCycle(rowGraph))
      return {};

    vector<int> rowLevels(k + 1);
    bfs(rowGraph, rowLevels, k);

    // vector<int> fixedRow(k + 1);
    // int rowIdx = 0;

    // for (auto v : rowLevels)
    //   for (auto i : v)
    //     if (i > 0)
    //       fixedRow.at(rowIdx++) = i;

    vector<vector<int>> colGraph(k + 1, vector<int>(k + 1));
    for (auto v : colConditions)
      colGraph.at(v.at(0)).at(v.at(1)) = 1;

    if (hasCycle(colGraph))
      return {};

    vector<int> columnLevels(k + 1);
    bfs(colGraph, columnLevels, k);

    // vector<int> fixedCol(k + 1);
    // int colIdx = 0;

    // for (auto v : columnLevels)
    //   for (auto i : v)
    //     if (i > 0)
    //       fixedCol.at(colIdx++) = i;

    // for (auto i : rowLevels)
    //   cout << i << " ";
    // cout << endl;

    // for (auto i : columnLevels)
    //   cout << i << " ";
    // cout << endl;

    vector<int> fixedRow(k);
    int rowIdx = 0;
    for (int i = 0; i <= k; i++)
    {
      for (int j = 1; j < rowLevels.size(); j++)
      {
        if (rowLevels.at(j) == i)
          fixedRow.at(rowIdx++) = j;
      }
    }

    vector<int> fixedCol(k);
    int colIdx = 0;
    for (int i = 0; i <= k; i++)
    {
      for (int j = 1; j < columnLevels.size(); j++)
      {
        if (columnLevels.at(j) == i)
          fixedCol.at(colIdx++) = j;
      }
    }

    for (auto i : fixedRow)
      cout << i << " ";
    cout << endl;

    for (auto i : fixedCol)
      cout << i << " ";
    cout << endl;

    vector<vector<int>> matrix(k, vector<int>(k));

    for (int i = 1; i <= k; i++)
    {
      int r = -1, c = -1;
      for (int j = 0; j < k; j++)
      {
        if (fixedRow.at(j) == i)
        {
          r = j;
          break;
        }
      }

      for (int j = 0; j < k; j++)
      {
        if (fixedCol.at(j) == i)
        {
          c = j;
          break;
        }
      }

      matrix.at(r).at(c) = i;
    }

    return matrix;
  }
};

int main()
{
  return 0;
}