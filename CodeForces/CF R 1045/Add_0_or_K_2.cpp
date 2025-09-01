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
    for (int i = 0; i < n; i++)
      cin >> arr.at(i);

    if (n == 1)
    {
      cout << arr.at(0) + k << endl;
      continue;
    }

    ll div = k + 1;

    for (int i = 0; i < n; i++)
    {
      arr.at(i) += (arr.at(i) % div) * k;
    }

    // cout << "ans:" << endl;
    for (auto i : arr)
      cout << i << " ";
    cout << endl;
  }

  return 0;
}