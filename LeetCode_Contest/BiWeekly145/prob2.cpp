#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findMinimumTime(vector<int> &strength, int K)
  {
    sort(strength.begin(), strength.end());
    int x{1}, sword_energy{0}, time = 0;

    while (strength.size() > 0)
    {
      sword_energy += x;
      time++;

      int strength_index{0};
      while (strength_index < strength.size() && sword_energy >= strength.at(strength_index))
        strength_index++;

      if (strength_index > 0)
      {
        strength.erase(strength.begin() + strength_index - 1);
        x += K;
        sword_energy = 0;
        cout << time << endl;
      }
    }

    return time;
  }
};

int main()
{
}
