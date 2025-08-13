#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long maxTotal(vector<int> &value, vector<int> &limit)
  {
    vector<vector<int>> combined(value.size(), vector<int>(2));

    for (int i = 0; i < combined.size(); i++)
    {
      combined.at(i).at(0) = limit.at(i);
      combined.at(i).at(1) = value.at(i);
    }

    sort(combined.begin(), combined.end(), [](const vector<int> &a, const vector<int> &b)
         {
           if (a[0] == b[0])
             return a[1] > b[1];
           return a[0] < b[0]; });

    // for (auto num : combined)
    //   cout << num.at(0) << " " << num.at(1) << endl;

    long long max_val = 0;
    for (int i = 0; i < combined.size(); i++)
    {
      int curr_lim = combined.at(i).at(0);
      int cnt = curr_lim;

      for (; i < combined.size() && cnt--; i++)
      {
        if (combined.at(i).at(0) == curr_lim)
          max_val += combined.at(i).at(1);
        else
          break;
      }

      for (; i < combined.size(); i++)
      {
        if (curr_lim != combined.at(i).at(0))
        {
          i--;
          break;
        }
      }
    }
    return max_val;
  }
};

int main()
{
  return 0;
}