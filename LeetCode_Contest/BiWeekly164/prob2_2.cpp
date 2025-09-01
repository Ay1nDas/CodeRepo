#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int score(vector<string> &cards, char x)
  {
    vector<int> first(10);
    vector<int> second(10);
    int both_cnt = 0;

    for (auto str : cards)
    {
      if (str.at(0) == x && str.at(1) == x)
      {
        both_cnt++;
        continue;
      }

      if (str.at(0) == x)
      {
        first.at(str.at(1) - 'a')++;
      }
      if (str.at(1) == x)
      {
        second.at(str.at(0) - 'a')++;
      }
    }

    // for (auto i : first)
    // {
    //   cout << i << " ";
    // }
    // cout << endl;

    // for (auto i : second)
    // {
    //   cout << i << " ";
    // }
    // cout << endl;
    // cout << both_cnt << endl;

    int total_1 = 0;
    int total_2 = 0;

    for (int i : first)
      total_1 += i;
    for (int i : second)
      total_2 += i;

    int negate = 0;

    for (auto i : first)
    {
      while (i > total_1 / 2)
      {
        total_1 -= i - total_1 / 2;
        i = total_1 / 2;
      }
    }

    for (auto i : second)
    {
      while (i > total_1 / 2)
      {
        total_1 -= i - total_1 / 2;
        i = total_1 / 2;
      }
    }
  }
};

int main()
{
  return 0;
}