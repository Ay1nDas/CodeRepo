#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long power(long long a, long long b)
  {
    if (b == 0)
    {
      return 1;
    }
    else if (b == 1)
    {
      return a;
    }

    long long remainderMultiply = 1;
    while (b > 1)
    {
      if (b % 2 == 0)
      {
        a *= a;
        b /= 2;
      }
      else
      {
        remainderMultiply *= a;
        a *= a;
        b = (b - 1) / 2;
      }
    }
    return remainderMultiply * a;
  }

  int waysToReachStair(int k)
  {
    vector<vector<int>> dp(k + 2, vector<int>(64));
    dp.at(1).at(0) = 1;
    dp.at(1).at(1) = 1;

    for (int i = 2; i <= k + 1; i++)
    {
      for (int j = 1; j <= 63; j++)
      {
        int prePow = power(2, j - 1);

        if (prePow <= i)
        {
          dp.at(i).at(j) = dp.at(i - prePow).at(j - 1) + dp.at(i - prePow + 1).at(j - 1);
        }
        else
        {
          break;
        }
      }
    }
    int finalVal = 0;
    for (int i = 0; i < 64; i++)
    {
      finalVal += dp.at(k).at(i) + dp.at(k + 1).at(i);
    }
    return finalVal;
  }
};

int main()
{
  return 0;
}