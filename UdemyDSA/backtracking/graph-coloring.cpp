#include <bits/stdc++.h>
using namespace std;

bool canColor(vector<vector<int>>& edges, vector<int>& nodes, int color, int node) {
  for (auto n : edges.at(node)) {
    if (nodes.at(n) == color) {
      return false;
    }
  }
  return true;
}

vector<vector<int>> coloredGraph(vector<vector<int>>& edges, vector<int>& nodes, int i, int colors) {
  if (i == nodes.size()) {
    return {nodes};
  }

  vector<vector<int>> result;
  for (int c = 0; c < colors; c++) {
    if (canColor(edges, nodes, c, i)) {
      nodes.at(i) = c;
      auto curr_res = coloredGraph(edges, nodes, i + 1, colors);
      result.insert(result.end(), curr_res.begin(), curr_res.end());
      nodes.at(i) = -1;
    }
  }

  return result;
}

int main()
{
  vector<vector<int>> edges = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
  vector<int> nodes(4, -1);

  for(auto vec : coloredGraph(edges, nodes, 0, 3)) {
    for(auto color : vec) {
      cout << color << " ";
    }
    cout << endl;
  }

  return 0;
}