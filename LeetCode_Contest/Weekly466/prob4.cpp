#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long nPalindrome(long long n, int binaryDigits)
  {
    if (binaryDigits <= 0)
      return 0;
    if (binaryDigits == 1)
      return (n >= 1) ? 1 : 0;

    long long count = 0;

    int firstHalfLen = (binaryDigits + 1) / 2;
    int secondHalfLen = binaryDigits / 2;
    long long start = 1LL << (firstHalfLen - 1);
    long long end = (1LL << firstHalfLen) - 1;

    for (long long i = start; i <= end; ++i)
    {
      long long firstHalf = i;
      long long palindrome = firstHalf;

      long long secondHalfRoot = firstHalf;
      if (binaryDigits % 2 != 0)
      {
        secondHalfRoot >>= 1;
      }

      long long reversedSecondHalf = 0;
      long long temp = secondHalfRoot;
      for (int j = 0; j < secondHalfLen; ++j)
      {
        reversedSecondHalf <<= 1;
        if (temp & 1)
        {
          reversedSecondHalf |= 1;
        }
        temp >>= 1;
      }

      palindrome <<= secondHalfLen;
      palindrome |= reversedSecondHalf;

      if (palindrome <= n)
        count++;
      else
        break;
    }

    return count;
  }

  long long power(long long a, long long b)
  {
    if (b == 0)
      return 1;

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

  int countBinaryPalindromes(long long n)
  {
    if (n == 0)
      return 1;

    long long n_cpy = n;
    int binary_digs = 0;
    while (n)
    {
      n /= 2;
      binary_digs++;
    }

    int palindromeCnt = 2;
    for (int i = 2; i < binary_digs; i++)
      palindromeCnt += power(2, (i - 1) / 2);

    return palindromeCnt + nPalindrome(n, binary_digs);
  }
};

int main()
{
  return 0;
}