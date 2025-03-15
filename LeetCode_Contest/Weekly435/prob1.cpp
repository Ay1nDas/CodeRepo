#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxDifference(string s)
  {
    vector<int> freq(26);

    for (auto c : s)
      freq.at(c - 'a')++;

    int odd = 0, even = 0;

    for (int i = 0; i < 26; i++)
    {
      if (freq.at(i) % 2 == 1)
      {
        odd = freq.at(i);
        break;
      }
    }

    for (int i = 25; i >= 0; i--)
    {
      if (freq.at(i) % 2 == 0 && freq.at(i) != 0)
      {
        even = freq.at(i);
        break;
      }
    }

    return odd - even;
  }
};

int main()
{
  return 0;
}