#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string findValidPair(string s)
  {
    unordered_map<int, int> digit_freq;

    for (auto c : s)
    {
      digit_freq[c - '0']++;
    }

    for (int i = 0; i + 1 < s.length(); i++)
    {
      if (s.at(i) - '0' == digit_freq[s.at(i) - '0'] && s.at(i + 1) - '0' == digit_freq[s.at(i + 1) - '0'] && s.at(i) != s.at(i + 1))
      {
        return s.substr(i, 2);
      }
    }
    return "";
  }
};

int main()
{
  return 0;
}