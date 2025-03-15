#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxAdjacentDistance(vector<int> &nums)
  {

    int max_diff = abs(nums.at(0) - nums.at(nums.size() - 1));

    for (int i = 1; i < nums.size(); i++)
    {
      int diff = abs(nums.at(i - 1) - nums.at(i));
      if (diff > max_diff)
      {
        max_diff = diff;
      }
    }
    return max_diff;
  }
};

int main()
{
  return 0;
}