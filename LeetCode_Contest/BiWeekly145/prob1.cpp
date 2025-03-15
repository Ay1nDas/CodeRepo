#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int minOperations(vector<int> &nums, int k)
  {
    sort(nums.begin(), nums.end());

    if (k > nums.at(0))
    {
      return -1;
    }

    int count{1};

    for (int i = 1; i < nums.size(); i++)
    {
      if (nums.at(i) != nums.at(i - 1))
        count++;
    }

    if (nums.at(0) == k)
      return count - 1;
    else
      return count;
  }
};

int main()
{
}