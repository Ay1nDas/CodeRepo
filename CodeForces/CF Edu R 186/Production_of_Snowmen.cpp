#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define all(x) (x).begin(), (x).end()
int mod = 1000000007;

int main()
{

  fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    ll n;
    cin >> n;

    vector<ll> a(n), b(n), c(n);

    for (auto &i : a)
    {
      cin >> i;
    }
    for (auto &i : b)
    {
      cin >> i;
    }
    for (auto &i : c)
    {
      cin >> i;
    }

    ll possAB = 0;

    for (int i = 0; i < n; i++)
    {
      bool isPoss = true;
      for (int j = 0; j < n; j++)
      {
        if (a.at(j) >= b.at((j + i) % n))
        {
          isPoss = false;
          break;
        }
      }
      if (isPoss)
      {
        possAB++;
      }
    }

    ll possBC = 0;

    for (int i = 0; i < n; i++)
    {
      bool isPoss = true;
      for (int j = 0; j < n; j++)
      {
        if (b.at(j) >= c.at((j + i) % n))
        {
          isPoss = false;
          break;
        }
      }
      if (isPoss)
      {
        possBC++;
      }
    }

    cout << n * possAB * possBC << endl;
  }
  return 0;
}
/*
4
1 2 1 2
3 3 2 2
5 5 5 5
*/