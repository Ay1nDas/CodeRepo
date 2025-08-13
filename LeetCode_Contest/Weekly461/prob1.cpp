#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isTrionic(vector<int> &nums)
  {
    int checks = 0;
    bool isInc;

    if (nums.at(0) < nums.at(1))
      isInc = true;
    else
      return false;

    for (int i = 2; i < nums.size(); i++)
    {
      if (isInc && nums.at(i) < nums.at(i - 1))
      {
        checks++;
        isInc = false;
      }
      else if (!isInc && nums.at(i) > nums.at(i - 1))
      {
        checks++;
        isInc = true;
      }
    }
    return checks == 2 ? true : false;
  }
};

int main()
{
  return 0;
}