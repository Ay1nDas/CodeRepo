#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
  bool hasMatch(string s, string p)
  {
    string p1, p2;
    for (int i = 0; i < p.length(); i++)
    {
      if (p.at(i) == '*')
      {
        p1 = p.substr(0, i);
        p2 = p.substr(i, p.length() - i);
      }
    }
    cout << p1 << p2 << endl;

    int p1_find = s.find(p1), p2_find = s.rfind(p2);

    if (s.find(p1) == string::npos || s.rfind(p2) == string::npos)
    {
      return false;
    }
    if (p1_find + p1.size() > p2_find)
    {
      return false;
    }

    return true;
  }
};

int main()
{
  return 0;
}
