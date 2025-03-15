#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> zigzagTraversal(vector<vector<int>> &grid)
  {
    bool take_it = true;
    vector<int> output;

    for (int i = 0; i < grid.size(); i++)
    {
      if (i % 2 == 0)
      {
        for (int j = 0; j < grid.at(i).size(); j++)
        {
          if (take_it)
            output.push_back(grid.at(i).at(j));
          take_it = !take_it;
        }
      }
      else
      {
        for (int j = grid.at(i).size() - 1; j >= 0; j--)
        {
          if (take_it)
            output.push_back(grid.at(i).at(j));
          take_it = !take_it;
        }
      }
    }

    return output;
  }
};

int main()
{
  return 0;
}