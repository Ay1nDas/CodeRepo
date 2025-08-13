#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y, int k)
  {
    for (int i = x; i < x + k / 2; i++)
    {
      for (int j = y; j < y + k; j++)
      {
        int tmp = grid.at(i).at(j);
        grid.at(i).at(j) = grid.at(x + k - 1 - (i - x)).at(j);
        grid.at(x + k - 1 - (i - x)).at(j) = tmp;
      }
    }
    return grid;
  }
};

int main()
{
  return 0;
}