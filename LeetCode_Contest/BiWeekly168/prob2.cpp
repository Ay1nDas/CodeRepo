#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string maxSumOfSquares(int num, int sum)
  {
    string n(num, 0);
    for (int i = 0; i < num; i++)
    {
      int value = min(9, sum);
      sum -= value;
      n.at(i) = (value + '0');
    }

    if (sum != 0)
    {
      return "";
    }
    else
    {
      return n;
    }
  }
};

int main()
{
  return 0;
}