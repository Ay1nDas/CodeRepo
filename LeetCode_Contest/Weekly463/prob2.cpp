#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int mod = 1000000007;

  int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
  {
    for (auto q : queries)
    {
      for (int idx = q.at(0); idx <= q.at(1); idx += q.at(2))
      {
        nums[idx] = (static_cast<long long>(nums[idx]) * q.at(3)) % mod;
      }
    }

    int XOR = 0;
    for (auto i : nums)
      XOR = XOR ^ i;
    return XOR;
  }
};

int main()
{
  return 0;
}