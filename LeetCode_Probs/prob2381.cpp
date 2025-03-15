#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string shiftingLetters(string s, vector<vector<int>> &shifts)
  {
    vector<int> str_shift(s.length());

    for (auto vec : shifts)
    {
      int add = (vec.at(2) ? 1 : 25);

      str_shift.at(vec.at(0)) += add;
      if (vec.at(1) + 1 < str_shift.size())
        str_shift.at(vec.at(1) + 1) -= add;
    }
    string reqd_s = s;
    int add_log = 0;

    for (int i = 0; i < s.length(); i++)
    {
      add_log += str_shift.at(i);
      reqd_s = (s.at(i) - 'a' + add_log) % 26 + 'a';
    }
    return reqd_s;
  }
};

int main()
{
  return 0;
}