#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> partitionString(string s)
  {
    unordered_map<string, int> mapped;

    string str;
    vector<string> output;

    for (int i = 0; i < s.length(); i++)
    {
      str += s.at(i);

      if (mapped[str] == 0)
      {
        mapped[str]++;
        output.push_back(str);
        str = "";
      }
    }
    return output;
  }
};

int main()
{
  return 0;
}