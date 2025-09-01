#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long maxProfit(vector<int> &prices, vector<int> &strategy, int k)
  {
    long long profit = 0;
    long long maxProf = 0;

    for (int i = 0; i < prices.size(); i++)
      profit += prices.at(i) * strategy.at(i);

    maxProf = profit;
    cout << profit << endl;

    for (int i = 0; i < k / 2; i++)
    {
      if (strategy.at(i) == -1)
        profit += prices.at(i);
      else if (strategy.at(i) == 1)
        profit -= prices.at(i);
    }
    for (int i = k / 2; i < k; i++)
    {
      if (strategy.at(i) == -1)
        profit += prices.at(i) * 2;
      else if (strategy.at(i) == 0)
        profit += prices.at(i);
    }

    maxProf = max(profit, maxProf);
    int bgn = 0;
    cout << profit << endl;

    while (bgn + k < prices.size())
    {
      profit += prices.at(bgn) * strategy.at(bgn);
      profit -= prices.at(bgn + k / 2);

      if (strategy.at(bgn + k) == -1)
        profit += prices.at(bgn + k) * 2;
      else if (strategy.at(bgn + k) == 0)
        profit += prices.at(bgn + k);
      bgn++;
      maxProf = max(maxProf, profit);
      cout << profit << endl;
    }

    return maxProf;
  }
};

int main()
{
  return 0;
}