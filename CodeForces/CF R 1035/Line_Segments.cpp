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
    ll px, py, qx, qy;
    cin >> n;
    cin >> px >> py >> qx >> qy;

    ll diff_square = (px - qx) * (px - qx) + (py - qy) * (py - qy);

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a.at(i);
    }

    sort(a.rbegin(), a.rend());
    ll min_val = a.at(0);
    ll max_val = a.at(0);

    for (int i = 1; i < n; i++)
    {
      min_val -= a.at(i);
      max_val += a.at(i);
    }

    if (min_val < 0)
      min_val = 0;

    min_val *= min_val;
    max_val *= max_val;

    // cout << "Data: " << min_val << " " << max_val << " " << diff_square << endl;

    if (diff_square >= min_val && diff_square <= max_val)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }

  return 0;
}