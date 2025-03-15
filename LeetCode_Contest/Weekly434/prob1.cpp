#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countPartitions(vector<int> &nums)
  {
    vector<int> prefix_sum(nums.size());
    prefix_sum.at(0) = nums.at(0);

    for (int i = 1; i < nums.size(); i++)
    {
      prefix_sum.at(i) = prefix_sum.at(i - 1) + nums.at(i);
    }

    int even_cnt = 0;

    for (int i = 1; i < nums.size(); i++)
    {
      if ((prefix_sum.at(nums.size() - 1) - prefix_sum.at(i) * 2) % 2 == 0)
      {
        even_cnt++;
      }
    }
  }
};

int main()
{
  return 0;
}