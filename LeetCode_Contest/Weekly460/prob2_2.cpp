#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long numOfSubsequences(string s)
  {
    int l_cnt = 0, c_cnt = 0, t_cnt = 0;
    long long ct_cnt = 0;
    long long ctt_cnt = 0;

    long long seq_cnt = 0;
    long long t_seq = 0;

    for (int i = s.length() - 1; i >= 0; i--)
    {
      if (s.at(i) == 'T')
      {
        t_cnt++;
      }
      else if (s.at(i) == 'C')
      {
        ct_cnt += t_cnt;
        ctt_cnt += t_cnt + 1;
        c_cnt++;
      }
      else if (s.at(i) == 'L')
      {
        seq_cnt += ct_cnt;
        t_seq += ctt_cnt;
        l_cnt++;
      }
    }

    long long l_seq = seq_cnt + ct_cnt;
    long long c_seq = 0;
    long long l = 0, t = t_cnt;

    for (int i = 0; i < s.length(); i++)
    {
      if (s.at(i) == 'L')
      {
        l++;
      }
      else if (s.at(i) == 'T')
      {
        t--;
      }

      c_seq = max(c_seq, l * t);
    }
    c_seq += seq_cnt;

    return max(l_seq, max(c_seq, t_seq));
  }
};

int main()
{
  return 0;
}