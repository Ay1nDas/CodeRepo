#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define all(x) (x).begin(), (x).end()
int MOD = 1000000007;

class Solution
{
public:
  int countCoprime(vector<vector<int>> &mat)
  {
    vector<vector<int>> &morindale = mat;

    int m = morindale.size();
    if (m == 0)
      return 0;
    int n = morindale.at(0).size();
    if (n == 0)
      return 0;

    int max_val = 0;
    for (const auto &row : morindale)
    {
      for (int val : row)
      {
        max_val = max(max_val, val);
      }
    }

    if (max_val == 0)
      return 0;

    vector<int> mu(max_val + 1);
    vector<int> min_prime(max_val + 1, 0);
    vector<int> primes;
    mu.at(1) = 1;

    for (int i = 2; i <= max_val; ++i)
    {
      if (min_prime.at(i) == 0)
      {
        min_prime.at(i) = i;
        mu.at(i) = -1;
        primes.push_back(i);
      }
      for (int p : primes)
      {
        if (i * static_cast<ll>(p) > max_val)
        {
          break;
        }
        min_prime.at(i * p) = p;
        if (i % p == 0)
        {
          mu.at(i * p) = 0;
          break;
        }
        else
        {
          mu.at(i * p) = -mu.at(i);
        }
      }
    }

    vector<vector<int>> row_freq(m, vector<int>(max_val + 1, 0));
    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (morindale.at(i).at(j) <= max_val)
        {
          row_freq.at(i).at(morindale.at(i).at(j))++;
        }
      }
    }
    vector<vector<ll>> div_counts(m, vector<ll>(max_val + 1, 0));
    for (int i = 0; i < m; ++i)
    {
      for (int g = 1; g <= max_val; ++g)
      {
        for (int k = g; k <= max_val; k += g)
        {
          div_counts.at(i).at(g) += row_freq.at(i).at(k);
        }
      }
    }

    ll total_ways = 0;
    for (int g = 1; g <= max_val; ++g)
    {
      if (mu.at(g) == 0)
      {
        continue;
      }

      ll ways_for_g = 1;
      for (int i = 0; i < m; ++i)
      {
        ways_for_g = (ways_for_g * div_counts.at(i).at(g)) % MOD;
      }

      ll term = (mu.at(g) * ways_for_g) % MOD;
      total_ways = (total_ways + term + MOD) % MOD;
    }

    return total_ways;
  }
};

int main()
{
  return 0;
}