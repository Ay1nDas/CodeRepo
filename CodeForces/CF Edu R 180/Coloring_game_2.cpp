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
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    sort(v.begin(), v.end());

    ll total = 0;

    // Case B: triples that include the global max v[n-1].
    // Count pairs i<j in [0..n-2] with v[i]+v[j] > v[n-1].
    {
      ll target = v[n - 1];
      int l = 0, r = n - 2;
      while (l < r)
      {
        if (v[l] + v[r] > target)
        {
          // all pairs (l, l+1..r-1) work with r
          total += (r - l);
          r--;
        }
        else
        {
          l++;
        }
      }
    }

    // Case A: triples among [0..n-2], excluding the global max.
    // For each k in [2..n-2], let z = v[k], T = max(z, v[n-1]-z),
    // count pairs i<j<k with v[i]+v[j] > T.
    for (int k = 2; k <= n - 2; k++)
    {
      ll z = v[k];
      ll T = max(z, v[n - 1] - z);
      int l = 0, r = k - 1;
      while (l < r)
      {
        if (v[l] + v[r] > T)
        {
          total += (r - l);
          r--;
        }
        else
        {
          l++;
        }
      }
    }

    cout << total << "\n";
  }
  return 0;
}