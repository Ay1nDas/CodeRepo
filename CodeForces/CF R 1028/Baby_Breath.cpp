#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define all(x) (x).begin(), (x).end()
int mod = 998244353;
int main()
{
  fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;

    vector<ll> pows(n);
    pows.at(0) = 1;

    for (int i = 1; i < n; i++)
      pows.at(i) = (pows.at(i - 1) * 2) % mod;

    vector<ll> perm1(n);
    vector<ll> max1(n);

    vector<ll> perm2(n);
    vector<ll> max2(n);

    cin >> perm1.at(0);
    max1.at(0) = 0;

    for (int i = 1; i < n; i++)
    {
      cin >> perm1.at(i);
      if (perm1.at(i) > perm1.at(max1.at(i - 1)))
        max1.at(i) = i;
      else
        max1.at(i) = max1.at(i - 1);
    }

    cin >> perm2.at(0);
    max2.at(0) = 0;

    for (int i = 1; i < n; i++)
    {
      cin >> perm2.at(i);
      if (perm2.at(i) > perm2.at(max2.at(i - 1)))
        max2.at(i) = i;
      else
        max2.at(i) = max2.at(i - 1);
    }

    for (int i = 0; i < n; i++)
    {
      ll r = max((pows.at(perm1.at(max1.at(i))) + pows.at(perm2.at(i - max1.at(i)))) % mod,
                 (pows.at(perm1.at(i - max2.at(i))) + pows.at(perm2.at(max2.at(i)))) % mod);

      cout << r << " ";
    }
    cout << endl;
  }

  return 0;
}