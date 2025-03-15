#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int sumOfGoodNumbers(vector<int> &nums, int k)
  {
    int end_sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (i - k >= 0 && nums.at(i) <= nums.at(i - k))
      {
        continue;
      }
      else if (i + k < nums.size() && nums.at(i) <= nums.at(i + k))
      {
        continue;
      }
      else
      {
        end_sum += nums.at(i);
      }
    }
    return end_sum;
  }
};

int main()
{
  return 0;
}