#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Modulo constant
long long MOD = 998244353;

// Function to calculate (base^exp) % MOD
long long power(long long base, long long exp)
{
  long long res = 1;
  base %= MOD;
  while (exp > 0)
  {
    if (exp % 2 == 1)
      res = (res * base) % MOD;
    base = (base * base) % MOD;
    exp /= 2;
  }
  return res;
}

// Function to calculate modular inverse
long long modInverse(long long n)
{
  return power(n, MOD - 2);
}

// Precompute factorials and inverse factorials
long long fact[60];
long long invFact[60];

void precompute()
{
  fact[0] = 1;
  invFact[0] = 1;
  for (int i = 1; i <= 55; i++)
  {
    fact[i] = (fact[i - 1] * i) % MOD;
    invFact[i] = modInverse(fact[i]);
  }
}

// nCr calculation
long long nCr(int n, int r)
{
  if (r < 0 || r > n)
    return 0;
  return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve()
{
  int n;
  cin >> n;
  vector<long long> a(n + 1);
  long long sum_total = 0;

  // Read input and calculate total decorations
  for (int i = 0; i <= n; i++)
  {
    cin >> a[i];
    sum_total += a[i];
  }

  // Determine baseline turns (k) and number of people with extra turn (r)
  long long k = sum_total / n;
  int r = sum_total % n;

  long long base_demand_sum = 0;
  int cnt1 = 0; // People with a[i] <= k (Group 1: Cost +1 if chosen for extra turn)
  int cnt2 = 0; // People with a[i] > k  (Group 2: Cost +0 if chosen for extra turn)

  // Analyze each person's contribution
  for (int i = 1; i <= n; i++)
  {
    // Demand on box 0 if this person takes exactly k turns
    long long demand_if_k = max(0LL, k - a[i]);
    base_demand_sum += demand_if_k;

    if (a[i] <= k)
    {
      cnt1++;
    }
    else
    {
      cnt2++;
    }
  }

  // Determine maximum allowed people from Group 1 in the "early" set
  // Constraint: base_demand + x * 1 + y * 0 <= a[0]
  // x <= a[0] - base_demand
  long long max_x = a[0] - base_demand_sum;

  // If base demand alone exceeds a[0], no solution exists
  if (max_x < 0)
  {
    cout << 0 << endl;
    return;
  }

  long long ans = 0;

  // Iterate over valid number of people chosen from Group 1 (x)
  for (int x = 0; x <= cnt1; x++)
  {
    // y is the number of people chosen from Group 2
    int y = r - x;

    // y must be non-negative and within the size of Group 2
    if (y < 0)
      continue;
    if (y > cnt2)
      continue;

    // Check fairness constraint
    if (x <= max_x)
    {
      // Ways to choose the sets
      long long ways = nCr(cnt1, x) * nCr(cnt2, y) % MOD;
      ans = (ans + ways) % MOD;
    }
  }

  // Multiply by permutations of the early group and the late group
  // Early positions: r!, Late positions: (n-r)!
  ans = (ans * fact[r]) % MOD;
  ans = (ans * fact[n - r]) % MOD;

  cout << "ANS: ";
  cout << ans << endl;
}

int main()
{
  // Optimize I/O
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  precompute();

  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}