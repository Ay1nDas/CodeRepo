#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int sortPermutation(vector<int> &nums)
  {
    int k = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums.at(i) != i)
        k = k & i;
    }
    return k;
  }
};

int main()
{
  return 0;
}