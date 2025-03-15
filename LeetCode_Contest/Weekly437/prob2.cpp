#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long maxWeight(vector<int> &pizzas)
  {
    int days = pizzas.size() / 4;

    sort(pizzas.rbegin(), pizzas.rend());
    long long weight = 0;
    int pizza_index = 0;
    // bool oddDay = true;

    for (int i = 1; i <= days; i += 2)
    {
      weight += pizzas.at(pizza_index);
      pizza_index++;
    }

    for (int i = 2; i <= days; i += 2)
    {
      weight += pizzas.at(pizza_index + 1);
      pizza_index += 2;
    }

    return weight;
  }
};

int main()
{
  return 0;
}