#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countTrapezoids(vector<vector<int>> &points)
  {
    unordered_map<int, long long> freq;
    int mod = 1000000007;

    for (auto i : points)
      freq[i.at(1)]++;

    vector<long long> combinations;
    long long comb_sum = 0;
    for (auto &pair : freq)
    {
      if (pair.second < 2)
        continue;

      combinations.push_back((pair.second * (pair.second - 1)) / 2);
      comb_sum += combinations.back();
    }

    long long totalComb = 0;
    for (int i = 0; i < combinations.size(); i++)
    {
      comb_sum -= combinations.at(i);
      totalComb += (comb_sum * combinations.at(i)) % mod;
      totalComb %= mod;
    }

    return totalComb % mod;
  }
};

int main()
{
  return 0;
}