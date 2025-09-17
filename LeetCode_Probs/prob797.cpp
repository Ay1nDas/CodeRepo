#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs(vector<vector<int>> &graph, vector<vector<int>> &paths, vector<int> &curr_path, vector<int> &traveled, int node, int destination)
  {
    if (node == destination)
      paths.push_back(curr_path);

    for (auto i : graph.at(node))
    {
      if (traveled.at(i) == 0)
      {
        curr_path.push_back(i);
        traveled.at(i) = 1;

        dfs(graph, paths, curr_path, traveled, i, destination);
      }
    }

    traveled.at(node) = 0;
    curr_path.pop_back();
  }

  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
  {
    vector<vector<int>> paths;
    vector<int> traveled(graph.size());
    vector<int> curr_path = {0};

    dfs(graph, paths, curr_path, traveled, 0, graph.size() - 1);

    return paths;
  }
};

int main()
{
  return 0;
}