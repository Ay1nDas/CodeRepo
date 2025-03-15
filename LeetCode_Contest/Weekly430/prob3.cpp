#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  long long numberOfSubsequences(vector<int> &nums)
  {
    long long count = 0;
    for (int p = 0; p < nums.size(); p++)
    {
      for (int r = p + 4; r + 2 < nums.size(); r++)
      {
        int value = nums.at(p) * nums.at(r);

        if (r - p - 3 >= nums.size() - r - 2)
        {
          unordered_map<int, int> nums_freq;
          for (int s = r + 2; s < nums.size(); s++)
            nums_freq[nums.at(s)]++;

          for (int q = p + 2; q + 1 < r; q++)
          {
            if (value % nums.at(q) == 0 && nums_freq[value / nums.at(q)])
              count += nums_freq[value / nums.at(q)];
          }
        }
        else
        {
          unordered_map<int, int> nums_freq;
          for (int q = p + 2; q + 1 < r; q++)
            nums_freq[nums.at(q)]++;

          for (int s = r + 2; s < nums.size(); s++)
          {
            if (value % nums.at(s) == 0 && nums_freq[value / nums.at(s)])
              count += nums_freq[value / nums.at(s)];
          }
        }
      }
    }

    return count;
  }
};

int main()
{
}