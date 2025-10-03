#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int evenNumberBitwiseORs(vector<int> &nums)
  {
    int bitwiseOR = 0;
    for (auto i : nums)
    {
      if (i % 2 == 0)
        bitwiseOR = bitwiseOR | i;
    }

    return bitwiseOR;
  }
};

int main()
{
  return 0;
}