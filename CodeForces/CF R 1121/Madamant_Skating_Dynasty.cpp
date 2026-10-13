#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define allrev(x) (x).rbegin(), (x).rend()
int mod =  998244353;

ll factorial(int n) {
  ll fact = 1;
  for (int i = 1; i <= n; i++) {
    fact = (fact * i) % mod;
  }

  return fact;
}

ll modpow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// void func(int a, int b) {}

int main()
{

  fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) {
      cin >> i;
    }

    sort(allrev(arr));

    vector<ll> prefix_sum(n);
    prefix_sum[0] = arr[0];
    for(int i = 1; i < n; i++) {
      prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    // cout << "Prefix: ";
    // for (auto &i : prefix_sum) {
    //   cout << i << " ";
    // }
    // cout << endl;

    ll tree_cnt = factorial(n - 1);
    // cout << tree_cnt << endl;
    // cout << func << endl;
    ll total_cost = 0;
    for (int i = 1; i < n; i++) {
      // cout << i << " " << prefix_sum[i - 1] << " " << arr[i] << " " << tree_cnt / i << endl;
      total_cost = (total_cost
                   + (((prefix_sum[i - 1] - (static_cast<ll>(i) * arr[i])) % mod)
                   * (tree_cnt * modpow(i, mod - 2, mod) % mod)) % mod)
                   % mod;
    }

    // cout << "Ans: ";
    cout << total_cost << endl;

  }

  return 0;
}
