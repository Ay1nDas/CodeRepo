#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isPowerOfThree(int n)
  {
    bool isPossible = (n ? true : false);
    while (n && isPossible)
    {
      if (n % 3)
        isPossible = false;
      n /= 3;
    }

    return isPossible;
  }
};

int main()
{
  return 0;
}