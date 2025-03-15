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

  int n;
  cin >> n;

  vector<ll> arr(n);
  cin >> arr.at(0);

  for (int i = 1; i < n; i++)
  {
    cin >> arr.at(i);
    arr.at(i) += arr.at(i - 1);
  }

  if (arr.at(n - 1) % 3 != 0)
  {
    cout << 0 << endl;
    return 0;
  }

  if (arr.at(n - 1) == 0)
  {
    ll zero_cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if (arr.at(i) == 0)
      {
        zero_cnt++;
      }
    }
    // cout << "Here1" << endl;
    cout << ((zero_cnt - 1) * (zero_cnt - 2)) / 2;
    return 0;
  }

  ll one_third = arr.at(n - 1) / 3;
  ll cnt = 0;
  ll two_third = 2 * (arr.at(n - 1) / 3);
  ll two_cnt = 0;

  for (int i = n - 1; i >= 0; i--)
  {
    if (arr.at(i) == one_third)
    {
      cnt += two_cnt;
    }
    if (arr.at(i) == two_third)
    {
      two_cnt++;
    }
  }
  // cout << one_third << " " << two_third << endl;
  // cout << "Here2" << endl;
  cout << cnt << endl;

  return 0;
}