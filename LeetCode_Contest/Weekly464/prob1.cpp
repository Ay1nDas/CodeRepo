#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long gcd(long long a, long long b)
  {
    int rem = b % a;
    if (rem == 0)
      return a;
    else
      return (rem, a);
  }

  int gcdOfOddEvenSums(int n)
  {
    long long oddSum = 0, evenSum = 0;

    for (int i = 1; i <= n; i++)
    {
      oddSum += i * 2 - 1;
      evenSum += i * 2;
    }
    return gcd(oddSum, evenSum);
  }
};

int main()
{
  return 0;
}