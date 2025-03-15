#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool hasSpecialSubstring(string s, int k)
  {
    int cnt = 1;
    for (int i = 0; i + 1 < s.length(); i++)
    {
      if (s.at(i) == s.at(i + 1))
      {
        cnt++;
      }
      else
      {
        if (cnt == k)
          return true;
        cnt = 1;
      }
    }

    if (cnt == k)
      return true;

    return false;
  }
};

int main()
{
  return 0;
}