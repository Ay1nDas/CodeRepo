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
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    ll idx = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> arr.at(i);

      if (arr.at(idx) < arr.at(i))
        idx = i;
    }

    ll multi = 1;
    ll points = 0;

    while (arr.at(idx) || k)
    {
      ll zero = 0, one = 0;

      for (int i = 0; i < n; i++)
      {
        if (arr.at(i) % 2)
          one++;
        else
          zero++;
        arr.at(i) /= 2;
      }
      points += one;

      if (k > zero * multi)
      {
        points += zero;
        k -= zero * multi;
      }
      else
      {
        points += k / multi;
        k = 0;
      }

      multi *= 2;
    }

    cout << points << endl;
  }

  return 0;
}