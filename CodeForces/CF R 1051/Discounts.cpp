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
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(k);

    for (int i = 0; i < n; i++)
      cin >> a.at(i);

    for (int i = 0; i < k; i++)
      cin >> b.at(i);

    sort(a.rbegin(), a.rend());
    sort(all(b));

    int idx = 0;
    int disIdx = 0;
    ll totalCost = 0;

    while (idx < n && disIdx < k)
    {
      int curr_dis = b.at(disIdx++);

      if (curr_dis > n - idx)
        break;

      for (int i = idx; i + 1 < idx + curr_dis; i++)
        totalCost += a.at(i);

      idx += curr_dis;
    }

    while (idx < n)
      totalCost += a.at(idx++);

    cout << totalCost << endl;
  }

  return 0;
}