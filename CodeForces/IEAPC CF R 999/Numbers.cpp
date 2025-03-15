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
    int n, m;
    cin >> n >> m;

    map<ll, ll> a;
    map<ll, ll> b;

    for (int i = 0; i < n; i++)
    {
      ll val;
      cin >> val;
      a[val]++;
    }
    for (int i = 0; i < m; i++)
    {
      ll val;
      cin >> val;
      b[val]++;
    }

    auto it_a = a.begin(), it_b = b.begin();
    ll lv_num = -1;
    ll lv_count = -1;
    // bool isPossible = true;

    while (it_a != a.end() && it_b != b.end())
    {

      if (lv_num != -1)
      {
        if (it_a->first - lv_num <= 1)
        {
          a[it_a->first + lv_num]++;
          lv_num = -1;

          it_a->second--;
          if (it_a->second == 0)
            it_a++;
        }
        else
        {
          // isPossible = false;
          break;
        }
      }

      if (it_a->first > it_b->first)
        break;

      if (it_a->first == it_b->first)
      {
        if (it_a->second >= it_b->second)
        {
          it_a->second -= it_b->second;
          it_b++;
        }
        else
        {
          // isPossible = false;
          break;
        }
      }

      if (it_a->second > 1)
      {
        a[(it_a->first) * 2] += (it_a->second) / 2;
      }
      if (it_a->second % 2 == 1)
      {
        lv_num = it_a->first;
      }
      it_a++; // Should be moved?
    }

    if (it_a == a.end() && it_b == b.end() && lv_num == -1)
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