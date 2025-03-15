#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  double separateSquares(vector<vector<int>> &squares)
  {
    unordered_map<int, int> start_end;
    std::sort(squares.begin(), squares.end(), [](const std::vector<int> &a, const std::vector<int> &b)
              { return a[1] < b[1]; });

    long long total_val = 0;

    for (int i = 0; i < squares.size(); i++)
    {
      start_end[squares.at(i).at(1)] += squares.at(i).at(2);
      start_end[squares.at(i).at(1) + squares.at(i).at(2) - 1] += squares.at(i).at(2);
      total_val += squares.at(i).at(2) * 2;
    }

    double target_val = total_val / 2;

    int end_index = squares.at(squares.size() - 1).at(1) + squares.at(squares.size() - 1).at(1);
    int running_area = 0;

    for (int i = 0; i < end_index; i++)
    {

      if (start_end[i] > 0)
      {
      }
    }
  }
};

int main()
{
  return 0;
}