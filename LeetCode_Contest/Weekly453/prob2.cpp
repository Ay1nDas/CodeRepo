#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;

class Solution
{
public:
  int countPermutations(vector<int> &complexity)
  {
    for (int i = 1; i < complexity.size(); i++)
    {
      if (complexity.at(i) <= complexity.at(0))
        return 0;
    }

    long long fact = 1;
    for (int i = 2; i < complexity.size(); i++)
      fact = (fact * i) % mod;
    return fact;
  }
};

int main()
{
  return 0;
}