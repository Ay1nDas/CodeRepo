#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define mod 1000000007

ll power(ll a, ll b)
{
  ll res = 1;
  a %= mod;
  while (b > 0)
  {
    if (b % 2 == 1)
    {
      res = (res * a) % mod;
    }
    a = (a * a) % mod;
    b /= 2;
  }
  return res;
}

ll modInverse(ll n)
{
  return power(n, mod - 2);
}

const int MAX_EXP = 65;
ll fact[MAX_EXP];
ll invFact[MAX_EXP];

void precomputeFactorials()
{
  fact[0] = 1;
  invFact[0] = 1;
  for (int i = 1; i < MAX_EXP; ++i)
  {
    fact[i] = (fact[i - 1] * i) % mod;
    invFact[i] = modInverse(fact[i]);
  }
}

ll modular_nCr(ll N, int k)
{
  if (k < 0)
    return 0;
  if (k == 0)
    return 1;

  ll num = 1;
  ll N_mod = N % mod;
  for (int i = 0; i < k; ++i)
  {
    num = (num * (N_mod + i)) % mod;
  }

  return (num * invFact[k]) % mod;
}

std::map<ll, int> getPrimeFactorization(ll B)
{
  std::map<ll, int> factors;
  if (B <= 1)
    return factors;

  while (B % 2 == 0)
  {
    factors[2]++;
    B /= 2;
  }

  for (ll i = 3; i * i <= B; i += 2)
  {
    while (B % i == 0)
    {
      factors[i]++;
      B /= i;
    }
  }

  if (B > 1)
  {
    factors[B]++;
  }
  return factors;
}

ll countWaysMod(ll N, std::map<ll, int> &factorization)
{
  ll totalWays = 1;
  for (auto const &[prime, exponent] : factorization)
  {
    ll waysForThisPrime = modular_nCr(N, exponent);
    totalWays = (totalWays * waysForThisPrime) % mod;
  }
  return totalWays;
}

std::map<ll, int> B_factors_global;
ll finalAnswer_global = 0;
ll N_global, A_global;
void solve(std::map<ll, int>::iterator it, ll current_P1, std::map<ll, int> &P1_factors)
{

  if (it == B_factors_global.end())
  {
    std::map<ll, int> P2_factors;
    for (auto const &[p, b_exp] : B_factors_global)
    {
      int a_exp = P1_factors.count(p) ? P1_factors[p] : 0;
      if (b_exp - a_exp > 0)
      {
        P2_factors[p] = b_exp - a_exp;
      }
    }

    ll ways1 = countWaysMod(N_global, P1_factors);
    ll ways2 = countWaysMod(N_global, P2_factors);

    finalAnswer_global = (finalAnswer_global + (ways1 * ways2) % mod) % mod;
    return;
  }

  auto [prime, max_exp] = *it;
  auto next_it = std::next(it);
  ll p_power = 1;

  for (int exp = 0; exp <= max_exp; ++exp)
  {
    if (p_power > 1 && (A_global / p_power < current_P1))
    {
      break;
    }

    ll new_P1 = current_P1 * p_power;

    if (exp > 0)
    {
      P1_factors[prime] = exp;
    }

    solve(next_it, new_P1, P1_factors);

    if (exp > 0)
    {
      P1_factors.erase(prime);
    }
    if (exp < max_exp)
    {
      p_power *= prime;
    }
  }
}

int main()
{

  ifstream infile("final_product_chapter_2_input.txt");
  ofstream outfile("final_product_chapter_2_output.txt");
  fast_io;
  int T;
  infile >> T;
  for (int test_case = 1; test_case <= T; test_case++)
  {
    outfile << "Case #" << test_case << ": ";
    ll n, a, b;
    infile >> n >> a >> b;
    if (a > b)
    {
      a = b;
    }

    finalAnswer_global = 0;
    B_factors_global.clear();
    N_global = n;
    A_global = a;
    precomputeFactorials();

    B_factors_global = getPrimeFactorization(b);

    std::map<ll, int> P1_factors_initial;
    solve(B_factors_global.begin(), 1, P1_factors_initial);

    outfile << finalAnswer_global << endl;
  }

  return 0;
}