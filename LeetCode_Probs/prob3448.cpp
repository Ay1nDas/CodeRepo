#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long countSubstrings(string s)
  {
    long long cnt = 0;
    for (int n = 1; n <= s.length(); n++)
    {
      for (int i = 0; i + n <= s.length(); i++)
      {
        long long num = stoi(s.substr(i, n));

        if (num % 10 != 0 && num % (num % 10) == 0)
          cnt++;
      }
    }
    return cnt;
  }
};

int main()
{
  return 0;
}