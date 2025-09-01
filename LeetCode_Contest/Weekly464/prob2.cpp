#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool partitionArray(vector<int> &nums, int k)
  {
    if (nums.size() % k != 0)
      return false;

    int part = nums.size() / k;
    unordered_map<int, int> freq;

    int max_freq = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      freq[nums.at(i)]++;

      if (freq[nums.at(i)] > max_freq)
        max_freq = freq[nums.at(i)];
    }

    if (max_freq > part)
      return false;
    else
      true;
  }
};

int main()
{
  return 0;
}