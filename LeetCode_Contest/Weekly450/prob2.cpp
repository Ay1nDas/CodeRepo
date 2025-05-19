#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minSwaps(vector<int> &nums)
  {
    unordered_map<int, vector<int>> freq;
    unordered_map<long long, long long> pos;
    int max_sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      int num = nums.at(i);
      pos[nums.at(i)] = i;
      int sum = 0;
      while (num)
      {
        sum += num % 10;
        num /= 10;
      }

      freq[sum].push_back(nums.at(i));
      max_sum = max(sum, max_sum);
    }

    int swap = 0;
    int index = 0;

    for (int i = 0; i <= max_sum; i++)
    {
      sort(freq[i].begin(), freq[i].end());
      for (int num : freq[i])
      {
        cout << num << " ";

        if (nums.at(index) != num)
        {
          int temp = nums.at(index);
          nums.at(index) = num;
          nums.at(pos[num]) = temp;

          int pos_temp = pos[temp];
          pos[temp] = pos[num];
          pos[num] = pos_temp;
          swap++;
        }
        index++;
      }
    }
    return swap;
  }
};

int main()
{
  return 0;
}
