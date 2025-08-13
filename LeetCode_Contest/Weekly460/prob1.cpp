#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long maximumMedianSum(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());

    int sz = nums.size();
    int idx = nums.size() - 2;
    long long sum = 0;
    while (sz)
    {
      sum += nums.at(idx);
      idx -= 2;
      sz -= 3;
    }

    return sum;
  }
};

int main()
{
  return 0;
}