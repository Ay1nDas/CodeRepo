#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> recoverOrder(vector<int> &order, vector<int> &friends)
  {
    unordered_map<int, int> freq;
    for (auto i : friends)
      freq[i]++;

    vector<int> frnd_order(friends.size());
    int frnd_idx = 0;

    for (auto i : order)
    {
      if (freq[i] > 0)
        frnd_order.at(frnd_idx++) = i;
    }

    return frnd_order;
  }
};

int main()
{
  return 0;
}