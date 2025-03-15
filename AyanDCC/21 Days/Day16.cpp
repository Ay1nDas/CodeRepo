#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define all(x) (x).begin(), (x).end()
int mod = 1000000007;

ll gcd(ll a, ll b)
{
  while (b != 0)
  {
    ll temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main()
{

  fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    ll a, b;
    cin >> a >> b;

    ll greatest_fact = gcd(a, b);

    a /= greatest_fact;
    b /= greatest_fact;

    int operations{0};

    while (a % 2 == 0)
    {
      a /= 2;
      operations++;
    }
    while (a % 3 == 0)
    {
      a /= 3;
      operations++;
    }
    while (a % 5 == 0)
    {
      a /= 5;
      operations++;
    }

    while (b % 2 == 0)
    {
      b /= 2;
      operations++;
    }
    while (b % 3 == 0)
    {
      b /= 3;
      operations++;
    }
    while (b % 5 == 0)
    {
      b /= 5;
      operations++;
    }

    if (a != 1 || b != 1)
      cout << -1 << endl;
    else
      cout << operations << endl;
  }

  return 0;
}