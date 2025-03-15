#include <bits/stdc++.h>
using namespace std;

class cls
{
public:
  string str;
  int num;

  cls(string s, int n)
  {
    str = s;
    num = n;
  }
  cls(string s)
  {
    str = s;
    num = 0;
  }

  cls()
  {
    str = "NONE";
    num = 0;
  }
};

int main()
{
  cls c1("Alex", 12);
  cls c2("Xu");
  // cls c1;
  cout << c1.num << endl;
  cout << c2.num << endl;
  return 0;
}