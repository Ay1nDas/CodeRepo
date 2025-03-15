#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long minCost(vector<int> &arr, vector<int> &brr, long long k)
  {
    bool isSort = false;
    long long t_cost1 = 0;

    for (int i = 0; i < arr.size(); i++)
    {
      t_cost1 += abs(arr.at(i) - brr.at(i));
      if (t_cost1 > k)
        isSort = true;
    }

    long long t_cost2 = LONG_LONG_MAX;
    if (isSort)
    {
      t_cost2 = k;
      vector<int> arr_cpy = arr, brr_cpy = brr; // If Time is issue, Do direct.

      sort(arr_cpy.begin(), arr_cpy.end());
      sort(brr_cpy.begin(), brr_cpy.end());
      for (int i = 0; i < arr_cpy.size(); i++)
      {
        t_cost2 += abs(arr_cpy.at(i) - brr_cpy.at(i));
      }
    }

    return min(t_cost1, t_cost2);
  }
};

int main()
{
  return 0;
}