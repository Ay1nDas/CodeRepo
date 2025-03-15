#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool maxSubstringLength(string s, int k)
  {
    unordered_map<int, int> mapping;

    vector<int> start_ch(26, -1);
    vector<int> end_ch(26, -1);

    for (int i = 0; i < s.length(); i++)
    {
      if (start_ch.at(s.at(i) - 'a') == -1)
      {
        start_ch.at(s.at(i) - 'a') = i;
        end_ch.at(s.at(i) - 'a') = i;
      }
      else
      {
        end_ch.at(s.at(i) - 'a') = i;
      }
    }

    for (int i = 0; i < start_ch.size(); i++)
    {
      if (start_ch.at(i) == -1)
      {
        continue;
      }

      mapping[start_ch.at(i)] = i + 1;
      mapping[end_ch.at(i)] = i + 1;

      if (start_ch.at(i) == end_ch.at(i))
      {
        k--;
      }
    }

    int running = -1;
    int sub_cnt = 0;

    if (k <= 0)
    {
      return true;
    }

    for (int i = 0; i <= s.length(); i++)
    {
      if (mapping[i] != 0 && running == -1)
      {
        running = mapping[i];
      }
      else if (mapping[i] != 0 && running == mapping[i])
      {
        running = -1;
        sub_cnt++;

        if (sub_cnt == k)
          return true;
      }
      else if (mapping[i] != 0 && running != mapping[i])
      {
        running = mapping[i];
      }
    }
    return false;
  }
};

int main()
{
  return 0;
}