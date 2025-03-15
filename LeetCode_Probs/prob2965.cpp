#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
  {
    unordered_map<int, int> freq;

    int twice = -1;
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid.at(i).size(); j++)
      {
        if (freq[grid.at(i).at(j)])
          twice = grid.at(i).at(j);

        freq[grid.at(i).at(j)];
      }
    }
    int missed = -1;
    for (int i = 1; i < grid.size() * 2 + 1; i++)
    {
      if (freq[i] == 0)
      {
        missed = i;
      }
    }
    vector<int> res{twice, missed};

    return res;
  }
};

int main()
{
  return 0;
}