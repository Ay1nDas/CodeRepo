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

long long power(long long a, long long b)
{
  if (b == 0)
    return 1;

  long long remainderMultiply = 1;
  while (b > 1)
  {
    if (b % 2 == 0)
    {
      a *= a;
      b /= 2;
    }
    else
    {
      remainderMultiply *= a;
      a *= a;
      b = (b - 1) / 2;
    }
  }
  return remainderMultiply * a;
}

// c -> v == 1  |  v -> c == 2

int main()
{

  fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    ll k, x;
    cin >> k >> x;
    ll c = x, v = power(2, k + 1) - x;

    vector<int> revOpp;

    while (c != v)
    {
      if (c > v)
      {
        c = c - v;
        v = 2 * v;
        revOpp.push_back(2);
      }
      else if (c < v)
      {
        v = v - c;
        c = 2 * c;
        revOpp.push_back(1);
      }
    }

    cout << revOpp.size() << endl;
    for (int i = revOpp.size() - 1; i >= 0; i--)
    {
      cout << revOpp.at(i) << " ";
    }
    cout << endl;
  }

  return 0;
}