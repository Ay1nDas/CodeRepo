#include <iostream>
#include <vector>
using namespace std;

int maxIncreasingSubarrays(vector<int> &nums)
{
  int before_cnt{1}, after_cnt{0};
  int neg_cnt{1};
  int max_cnt{0};

  for (int i = 1; i < nums.size(); i++)
  {
    int diff = nums.at(i) - nums.at(i - 1);

    if (diff > 0 && neg_cnt == 0)
    {
      after_cnt++;
    }
    else if (diff > 0)
    {
      before_cnt++;
    }
    else if (neg_cnt > 0)
    {
      after_cnt++;
      neg_cnt--;
    }
    else
    {
      int curr_cnt = max(min(before_cnt, after_cnt), max(before_cnt, after_cnt) / 2);

      if (max_cnt < curr_cnt)
        max_cnt = curr_cnt;

      before_cnt = after_cnt;
      after_cnt = 1;
    }

    // cout << before_cnt << endl
    //      << after_cnt << endl
    //      << endl;
  }

  int curr_cnt = max(min(before_cnt, after_cnt), max(before_cnt, after_cnt) / 2);
  if (max_cnt < curr_cnt)
    max_cnt = curr_cnt;

  return max_cnt;
}

int main()
{
}