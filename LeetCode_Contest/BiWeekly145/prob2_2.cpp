#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findMinimumTime(vector<int> &strength, int K)
  {
    sort(strength.begin(), strength.end());
    int max_time{INT_MAX};

    do
    {
      int strength_index{0}, time{0}, sword_str{0}, x{1};
      while (strength_index < strength.size())
      {
        time += strength.at(strength_index) / x;
        sword_str = (strength.at(strength_index) / x) * x;

        if (strength.at(strength_index) % x)
        {
          time++;
          sword_str += x;
        }

        if (sword_str >= strength.at(strength_index))
        {
          strength_index++;
          x += K;
        }
      }

      if (time < max_time)
        max_time = time;

    } while (next_permutation(strength.begin(), strength.end()));

    return max_time;
  }
};

int main()
{
}