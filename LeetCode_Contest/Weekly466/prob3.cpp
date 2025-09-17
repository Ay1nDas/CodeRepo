#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long bowlSubarrays(vector<int> &nums)
  {
    vector<int> leftLarger(nums.size());
    int lMax = nums.at(0);
    for (int i = 1; i < nums.size(); i++)
    {
      if (lMax > nums.at(i))
        leftLarger.at(i) = 1;
      else
        lMax = nums.at(i);
    }

    vector<int> rightLarger(nums.size());
    int rMax = nums.at(nums.size() - 1);
    for (int i = nums.size() - 2; i >= 0; i--)
    {
      if (rMax > nums.at(i))
        rightLarger.at(i) = 1;
      else
        rMax = nums.at(i);
    }

    long long cnt = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      if (leftLarger.at(i) && rightLarger.at(i))
        cnt++;
    }

    return cnt;
  }
};

int main()
{
  return 0;
}