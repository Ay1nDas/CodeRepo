#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string lexSmallest(string s)
  {
    string smallest = s;
    for (int i = 0; i < s.length(); i++)
    {
      string str1 = s, str2 = s;
      reverse(str1.begin(), str1.begin() + i);
      reverse(str2.begin() + i, str2.end());

      smallest = min(smallest, min(str1, str2));
    }

    return smallest;
  }
};

int main()
{
  return 0;
}