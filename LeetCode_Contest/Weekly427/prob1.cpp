#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> constructTransformedArray(vector<int> &nums)
  {
    vector<int> result(nums.size());

    for (int i = 0; i < nums.size(); i++)
    {
      int n{0};
      if (nums.at(i) >= 0)
        n = (i + nums.at(i)) % nums.size();
      else if (nums.at(i) < 0)
      {
        n = (i + nums.at(i)) % nums.size();
        if (n < nums.size())
          n += nums.size();
      }

      result.at(n) = nums.at(i);
    }
    return result;
  }
};

int main()
{
}