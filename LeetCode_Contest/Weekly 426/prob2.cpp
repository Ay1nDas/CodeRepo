#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int getLargestOutlier(vector<int> &nums)
  {
    int sum{0};
    unordered_map<int, int> freq;
    for (auto i : nums)
    {
      freq[i]++;
      sum += i;
    }
    int return_num{-1001};
    for (auto i : nums)
    {
      freq[i]--;
      if (freq[(sum - i) / 2] && (sum - i) % 2 == 0 && return_num < i)
        return_num = i;
      freq[i++];
    }

    return return_num;
  }
};

int main()
{
}