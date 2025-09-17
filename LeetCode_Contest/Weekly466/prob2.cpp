#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minOperations(string s)
  {
    int letter[26] = {0};
    for (auto c : s)
      letter[c - 'a']++;

    int opp_cnt = 26;
    for (int i = 1; i < 26; i++)
    {
      if (letter[i] != 0)
      {
        opp_cnt = i;
        break;
      }
    }

    return 26 - opp_cnt;
  }
};

int main()
{
  return 0;
}