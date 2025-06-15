#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxSumDistinctTriplet(vector<int> &x, vector<int> &y)
  {
    unordered_map<int, int> max_y;

    for (int i = 0; i < x.size(); i++)
      max_y[x.at(i)] = max(max_y[x.at(i)], y.at(i));

    vector<int> y_vals;
    for (const auto &pair : max_y)
      y_vals.push_back(pair.second);

    sort(y_vals.rbegin(), y_vals.rend());

    if (y_vals.size() > 2 && y_vals.at(2))
    {
      return y_vals.at(0) + y_vals.at(1) + y_vals.at(2);
    }
    else
    {
      return -1;
    }
  }
};

int main()
{
  return 0;
}