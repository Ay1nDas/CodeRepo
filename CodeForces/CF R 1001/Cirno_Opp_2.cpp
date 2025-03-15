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
    vector<ll> seq(n);
    ll max_sum = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> seq.at(i);
      max_sum += seq.at(i);
    }

    ll cnt = n;
    while (cnt > 1)
    {
      ll cur_sum = 0;
      if (abs(seq.at(cnt - 1) - seq.at(0)) > max_sum)
      {
        max_sum = abs(seq.at(cnt - 1) - seq.at(0));
      }

      for (int j = 0; j + 1 < cnt; j++)
      {
        seq.at(j) = seq.at(j + 1) - seq.at(j);
      }
      cnt--;
    }

    if (seq.at(0) > max_sum)
    {
      max_sum = seq.at(0);
    }

    cout << max_sum << endl;
  }

  return 0;
}