#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long maxProfit(vector<int> &prices, vector<int> &strategy, int k)
  {
    vector<int> buys;
    vector<int> holds;
    vector<int> sells;
    long long profit = 0;

    for (int i = 0; i < strategy.size(); i++)
    {
      if (strategy.at(i) == -1)
      {
        buys.push_back(prices.at(i));
        profit -= prices.at(i);
      }
      else if (strategy.at(i) == 0)
      {
        holds.push_back(prices.at(i));
      }
      else
      {
        sells.push_back(prices.at(i));
        profit += prices.at(i);
      }
    }

    long long currProfit = profit;

    sort(buys.rbegin(), buys.rend());
    sort(holds.rbegin(), holds.rend());

    sort(sells.begin(), sells.end());
    int k_left1 = 0;
    if (k / 2 <= buys.size())
    {
      for (int i = 0; i < k / 2; i++)
        profit += buys.at(i);
    }
    else
    {
      for (int i = 0; i < buys.size(); i++)
        profit += buys.at(i);
      k_left1 = k / 2 - buys.size();
    }

    // long long profit1 = profit;
    // long long profit2 = profit;

    if (k / 2 + k_left1 <= holds.size())
    {
      for (int i = 0; i < k / 2; i++)
        profit += holds.at(i);
    }
    else
    {
      int holds_left = k / 2 < holds.size() ? holds.size() - k / 2 : 0;
      int k_left2 = k_left1 - holds_left;

      if (holds.size() >= k / 2)
      {
        for (int i = 0; i < k / 2; i++)
          profit += holds.at(i);
      }
      else
      {
        for (int i = 0; i < holds.size(); i++)
          profit += holds.at(i);
      }

      while (k_left2--)
      {
      }
    }

    return profit;
  }
};

int main()
{
  return 0;
}