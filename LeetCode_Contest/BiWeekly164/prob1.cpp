#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int getLeastFrequentDigit(int n)
  {
    vector<int> freq(10);
    while (n)
    {
      freq.at(n % 10)++;
      n /= 10;
    }

    int min_freq = INT_MAX;
    int min_freq_idx = -1;

    for (int i = 0; i < 10; i++)
    {
      if (freq.at(i) < min_freq)
      {
        min_freq = freq.at(i);
        min_freq_idx = i;
      }
    }
    return min_freq_idx;
  }
};

int main()
{
  return 0;
}