#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canMakeEqual(vector<int> &nums, int k)
  {
    int minus_req = 0;
    bool minus_running = false;

    for (int i = 0; i < nums.size(); i++)
    {
      if (minus_running)
        minus_req++;
      if (nums.at(i) == -1)
        minus_running = !minus_running;
    }

    if (minus_req <= k && !minus_running)
      return true;

    int plus_req = 0;
    bool plus_running = false;

    for (int i = 0; i < nums.size(); i++)
    {
      if (plus_running)
        plus_req++;
      if (nums.at(i) == 1)
        plus_running = !plus_running;
    }

    if (plus_req <= k && !plus_running)
      return true;
    else
      return false;
  }
};

int main()
{
  return 0;
}