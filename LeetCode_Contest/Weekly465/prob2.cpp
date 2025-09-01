#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  std::vector<int> factors(int n)
  {
    std::vector<int> primeFactors;

    while (n % 2 == 0)
    {
      primeFactors.push_back(2);
      n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2)
    {
      while (n % i == 0)
      {
        primeFactors.push_back(i);
        n = n / i;
      }
    }

    if (n > 2)
    {
      primeFactors.push_back(n);
    }

    return primeFactors;
  }

  void findSplits(vector<int> &facts, int n, int k, int idx, vector<int> &splits)
  {
    if (idx == k)
    {
      for (int i : splits)
        cout << i << " ";
      cout << endl;

      return;
    }
    for (int i = 2; i < splits.at(0); i++)
    {
      if (splits.at(0) % i == 0)
      {
        splits.at(idx) *= i;
        splits.at(0) /= i;
        findSplits(facts, n, k, idx + 1, splits);
      }
    }
  }

  vector<int> minDifference(int n, int k)
  {

    vector<int> facts = factors(n);
    vector<int> splits(k, 1);
    splits.at(0) = n;
    findSplits(facts, n, k, 1, splits);

    return splits;
  }
};
int main()
{
  return 0;
}