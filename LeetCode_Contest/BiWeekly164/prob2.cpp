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

    for (auto i : first)
    {
      cout << i << " ";
    }
    cout << endl;

    for (auto i : second)
    {
      cout << i << " ";
    }
    cout << endl;
    cout << both_cnt << endl;

    sort(first.rbegin(), first.rend());
    sort(second.rbegin(), second.rend());

    int buff = first.at(0);
    int total1 = 0;
    int total2 = 0;
    int paired_2 = 0;

    for (int i = 1; i < 10; i++)
    {
      if (buff >= first.at(i))
      {
        total1 += first.at(i);
        buff -= first.at(i);
      }
      else
      {
        total1 += buff;
        buff = first.at(i) - buff;
      }
    }

    if (buff >= both_cnt)
    {
      paired_2 += both_cnt;
      buff -= both_cnt;
      both_cnt = 0;
    }
    else
    {
      paired_2 += buff;
      both_cnt -= buff;
      buff = 0;
    }

    if (first.at(3) > 0)
      buff /= 2;
    if (total1 >= buff)
    {
      paired_2 += buff * 2;
      total1 -= buff;
    }
    else
    {
      total1 = 0;
      paired_2 += total1 * 2;
    }

    buff = second.at(0);
    for (int i = 1; i < 10; i++)
    {
      if (buff >= second.at(i))
      {
        total2 += second.at(i);
        buff -= second.at(i);
      }
      else
      {
        total2 += buff;
        buff = second.at(i) - buff;
      }
    }

    if (buff >= both_cnt)
    {
      paired_2 += both_cnt;
      both_cnt = 0;
    }
    else
    {
      paired_2 += buff;
      both_cnt -= buff;
    }

    buff /= 2;
    if (total2 >= buff)
    {
      paired_2 += buff * 2;
      total2 -= buff;
    }
    else
    {
      total2 = 0;
      paired_2 += total2 * 2;
    }

    both_cnt /= 2;

    if (total1 + total2 >= both_cnt)
    {
      total2 += both_cnt;
    }
    else
    {
      total2 *= 2;
    }

    return total1 + total2 + paired_2;
  }
};

int main()
{
  return 0;
}