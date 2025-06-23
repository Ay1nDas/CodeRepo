#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int primes[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

  bool checkPrimeFrequency(vector<int> &nums)
  {
    unordered_map<int, int> freq;

    for (auto i : nums)
    {
      freq[i]++;
    }

    bool isPrime = false;
    for (int i = 0; i <= 100; i++)
    {
      int prime_index = 0;
      while (prime_index < 25 && freq[i] > primes[prime_index])
      {
        prime_index++;
      }
      if (prime_index < 25 && freq[i] == primes[prime_index])
      {
        isPrime = true;
        break;
      }
    }
    return isPrime;
  }
};

int main()
{
  return 0;
}