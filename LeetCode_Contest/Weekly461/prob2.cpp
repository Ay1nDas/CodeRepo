#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxBalancedShipments(vector<int> &weight)
  {
    int max_wei = 0;
    int shipment_cnt = 0;
    for (int i = 0; i < weight.size(); i++)
    {
      if (weight.at(i) < max_wei)
      {
        shipment_cnt++;
        max_wei = 0;
      }
      else
      {
        max_wei = max(weight.at(i), max_wei);
      }
    }
    return shipment_cnt;
  }
};

int main()
{
  return 0;
}
