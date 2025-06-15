#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long maximumProfit(vector<int> &prices, int k)
  {
    vector<int> diff(prices.size());
    diff.at(0) = 0;

    for (int i = 0; i + 1 < prices.size(); i++)
      diff.at(i + 1) = prices.at(i + 1) - prices.at(i);

    vector<long long> poss_tran;
    long long curr_val = 0;
    bool pos = true;
    for (int i = 1; i < diff.size(); i++)
    {
      if (pos && diff.at(i) > 0)
      {
        curr_val += diff.at(i);
      }
      else if (!pos && diff.at(i) < 0)
      {
        curr_val += diff.at(i);
      }
      else
      {
        long long check_val = 0;
        if (i > 0)
          check_val += diff.at(i - 1);
        if (i + 1 < diff.size() && diff.at(i + 1) > 0 && diff.at(i) < 0)
          check_val += diff.at(i + 1);
        else if (i + 1 < diff.size() && diff.at(i + 1) < 0 && diff.at(i) < 0)
          check_val += diff.at(i + 1);

        if (abs(check_val) > abs(diff.at(i)))
        {
          pos = !pos;
          poss_tran.push_back(abs(curr_val));
          curr_val = 0;
        }
        else
        {
          pos = !pos;
          poss_tran.push_back(abs(curr_val - diff.at(i - 1)));
          curr_val = diff.at(i);
        }
      }
    }
    poss_tran.push_back(abs(curr_val));

    // for (auto p : poss_tran)
    // {
    //   cout << p << " ";
    // }
    // cout << endl;
    // return 0;

    sort(poss_tran.rbegin(), poss_tran.rend());

    long long val = 0;
    for (int i = 0; i < poss_tran.size() && i < k; i++)
      val += poss_tran.at(i);
    return val;
  }
};

int main()
{
  return 0;
}