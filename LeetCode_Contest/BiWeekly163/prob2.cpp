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

    for (int i = 0; i < abs_nums.size() - 1; i++)
    {
      int find = abs_nums.at(i) * 2 + 1;

      int start = i;
      int end = abs_nums.size() - 1;

      while (start < end)
      {
        int mid = (start + end) / 2;
        cout << i << " " << start << " " << end << endl;

        if (find > abs_nums.at(mid))
          start = mid + 1;
        else if (find < abs_nums.at(mid))
          end = mid - 1;
        else
          start = end = mid;
      }

      find--;
      while (abs_nums.at(start) > find)
        start--;

      total_cnt += start - i;
    }

    return total_cnt;
  }
};

int main()
{
  return 0;
}