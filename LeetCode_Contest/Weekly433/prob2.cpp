#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;

class Solution
{
public:
  long long comb(int n, int r)
  {
    r = min(r, n - r);

    if (r == 0)
      return 1;

    long long numerator = 1, denominator = 1;

    for (int i = 0; i < r; i++)
    {
      numerator *= n;
      denominator *= i + 1;
      n--;
    }
    return numerator / denominator;
  }

  int minMaxSums(vector<int> &nums, int k)
  {
    vector<long long> sum;

    int min = INT_MAX, max = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums.at(i) > max)
        max = nums.at(i);
      if (nums.at(i) < min)
        min = nums.at(i);
    }

    long long val = max + min;

    for (int i = 1; i <= k; i++)
    {
      sum.push_back((val * comb(nums.size(), i)) % mod);
    }

    long long final_sum = 0;
    for (auto s : sum)
    {
      final_sum += s;
    }

    return final_sum % mod;
  }
};

int main()
{
  return 0;
}