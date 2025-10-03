#include <bits/stdc++.h>
using namespace std;

string LCS(string &str1, string &str2, int l1, int l2)
{
  if (l1 == 0 || l2 == 0)
    return "";
  else if (str1.at(l1) == str2.at(l2))
    return LCS(str1, str2, l1 - 1, l2 - 1) + str1.at(l1);

  string rmv1 = LCS(str1, str2, l1 - 1, l2);
  string rmv2 = LCS(str1, str2, l1, l2 - 1);

  if (rmv1.length() > rmv2.length())
    return rmv1;
  else
    return rmv2;
}

int main()
{
  string str1 = "abcdefg";
  string str2 = "dbcfmg";

  str1 = " " + str1;
  str2 = " " + str2;

  cout << LCS(str1, str2, str1.size() - 1, str2.size() - 1) << endl;
  return 0;
}