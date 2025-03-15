#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int subarraySum(vector<int> &nums)
  {
    vector<int> prefix_nums(nums.size());
    prefix_nums.at(0) = nums.at(0);
    int start = 0;
    int tot_sum = 0;

    for (int i = 1; i < nums.size(); i++)
    {
      prefix_nums.at(i) = nums.at(i) + prefix_nums.at(i - 1);

      start = max(0, i - nums.at(i));

      tot_sum += prefix_nums.at(i) - prefix_nums.at(start) + nums.at(start);
    }

    return tot_sum;
  }
};

int main()
{
  return 0;
}