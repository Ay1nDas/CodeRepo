#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> processQueries(int c, vector<vector<int>> &connections, vector<vector<int>> &queries)
  {
    vector<vector<int>> connected_grids(c);
    unordered_map<int, int> cons;
    int grid_idx = 0;

    for (auto i : connections)
    {
      if (cons[i.at(0)] == 0 && cons[i.at(1)] == 0)
      {
        grid_idx++;
        cons[i.at(0)] = grid_idx;
        cons[i.at(1)] = grid_idx;

        connected_grids.at(grid_idx - 1).push_back(i.at(0));
        connected_grids.at(grid_idx - 1).push_back(i.at(1));
      }
      else if (cons[i.at(0)])
      {
        cons[i.at(1)] = cons[i.at(0)];
        connected_grids.at(cons.at(i.at(0)) - 1).push_back(i.at(1)); // does cons throw exp
      }
      else
      {
        cons[i.at(0)] = cons[i.at(1)];
        connected_grids.at(cons.at(i.at(1)) - 1).push_back(i.at(0)); // does cons throw exp
      }
    }

    vector<int> res;
    for (auto q : queries)
    {
      if (q.at(0) == 2)
      {
        int stn = q.at(1);
      }
    }
  }
};

int main()
{
  return 0;
}