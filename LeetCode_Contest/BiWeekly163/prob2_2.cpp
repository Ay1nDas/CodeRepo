#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long perfectPairs(vector<int> &nums)
  {
    vector<int> abs_nums(nums.size());

    for (int i = 0; i < nums.size(); i++)
      abs_nums.at(i) = nums.at(i) > 0 ? nums.at(i) : -nums.at(i);

    sort(abs_nums.begin(), abs_nums.end());

    // for (auto i : abs_nums)
    //   cout << i << " ";

    long long total_cnt = 0;
    int end_idx = 0;

    for (int i = 0; i < abs_nums.size() - 1; i++)
    {
      int find = abs_nums.at(i) * 2;

      while (end_idx < abs_nums.size() && abs_nums.at(end_idx) <= find)
      {
        end_idx++;
      }

      total_cnt += end_idx - i - 1;
    }

    return total_cnt;
  }
};

int main()
{
  return 0;
}