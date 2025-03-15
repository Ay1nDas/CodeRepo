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

    long long current_sum = 0;
    for (auto i : nums)
      current_sum += i;

    sum.push_back((current_sum * 2) % mod);
    sort(nums.begin(), nums.end());

    int it = 0;
    while (k-- > 1)
    {
      int count = nums.size() - k + 1;
      current_sum = 0;

      while (count--)
      {
        current_sum += nums.at(it) * comb(nums.size() - it - 1, k) + nums.at(nums.size() - 1 - it) * comb(nums.size() - it - 1, k);
        it++;
      }
      sum.push_back(current_sum % mod);
    }

    long long final_sum = 0;
    for (auto s : sum)
    {
      cout << s << endl;
      final_sum += s;
    }
    return final_sum % mod;
  }
};

int main()
{
  return 0;
}