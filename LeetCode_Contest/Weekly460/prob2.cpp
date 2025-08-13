#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long numOfSubsequences(string s)
  {
    int l_cnt = 0, c_cnt = 0, t_cnt = 0;

    for (int i = 0; i < s.length(); i++)
    {
      switch (s.at(i))
      {
      case 'L':
        l_cnt++;
        break;
      case 'C':
        c_cnt++;
        break;
      case 'T':
        t_cnt++;
        break;
      }
    }

    long long l = l_cnt, c = c_cnt, t = t_cnt;

    long long l_sum = c * t;
    long long c_sum = 0;
    long long t_sum = 0;

    for (int i = 0; i < s.length(); i++)
    {
      if (s.at(i) == 'L')
      {
        l_sum += c * t;
        c_sum += (c + 1) * t;
        t_sum += c * (t + 1);
      }
      else if (s.at(i) == 'C')
      {
        c--;
      }
      // else if()
    }
  }
};

int main()
{
  return 0;
}