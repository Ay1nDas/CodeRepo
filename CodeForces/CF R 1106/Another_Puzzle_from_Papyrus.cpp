#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
int mod = 1000000007;

int main()
{

  fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    int n, c;
    cin >> n >> c;
    vector<int> a(n), b(n);
    for (auto &i: a) {
      cin >> i;
    }
    for (auto &i: b) {
      cin >> i;
    }

    int sub_cnt = 0;
    for (int i = 0; i < n; i++) {
      if(a.at(i) < b.at(i)) {
        sub_cnt = INT_MAX;
        break;
      }
      sub_cnt += a.at(i) - b.at(i);
    }

    sort(all(a));
    sort(all(b));

    int re_cnt = c;
    for (int i = 0; i < n; i++) {
      if(a.at(i) < b.at(i)) {
        re_cnt = INT_MAX;
        break;
      }
      re_cnt += a.at(i) - b.at(i);
    }

    int min_cnt = min(sub_cnt, re_cnt);
    if(min_cnt == INT_MAX) {
      cout << -1 << endl;
    } else {
      cout << min_cnt << endl;
    }
  }

  return 0;
}