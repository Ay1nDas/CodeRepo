#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  int minimumOperations(vector<vector<int>> &grid)
  {
    int opps = 0;
    for (int r = 0; r < grid.at(0).size(); r++)
    {
      int column_val = grid.at(0).at(r);
      for (int c = 0; c < grid.size(); c++)
      {
        opps += max(grid.at(c).at(r), column_val) - grid.at(c).at(r);
        column_val = max(grid.at(c).at(r), column_val) + 1;
      }
    }

    return opps;
  }
};

int main()
{
}