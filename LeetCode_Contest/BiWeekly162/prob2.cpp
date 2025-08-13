#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minRemoval(vector<int> &nums, int k)
  {
    vector<int> nums_cpy = nums;
    sort(nums_cpy.begin(), nums_cpy.end());
    int remove = INT_MAX;

    for (int i = 0; i < nums_cpy.size(); i++)
    {
      int curr_rmv = i;
      long long max_val = static_cast<long long>(nums_cpy.at(i)) * k;

      if (max_val > nums_cpy.back())
      {
        remove = min(curr_rmv, remove);
        break;
      }

      int l = i + 1, m = nums_cpy.size() - 1;

      while (l < m)
      {
        int mid = (l + m) / 2;

        if (nums_cpy.at(mid) < max_val)
        {
          l = mid + 1;
        }
        else if (nums_cpy.at(mid) > max_val)
        {
          m = mid;
        }
        else
        {
          l = m = mid + 1;
          break;
        }
      }

      while (l < nums_cpy.size() && nums_cpy.at(l) < max_val)
        l++;
      curr_rmv += nums_cpy.size() - l;

      remove = min(curr_rmv, remove);
    }

    return remove;
  }
};

int main()
{
  return 0;
}