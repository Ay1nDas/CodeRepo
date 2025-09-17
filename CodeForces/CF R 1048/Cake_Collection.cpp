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
    int n, m;
    cin >> n >> m;

    vector<int> ovens(n);

    for (int i = 0; i < n; i++)
      cin >> ovens.at(i);

    sort(all(ovens));

    ll totalCakes = 0;
    for (int i = ovens.size() - 1; i >= 0; i--)
    {
      totalCakes += static_cast<ll>(ovens.at(i)) * m;
      if (m > 0)
        m--;
    }

    cout << totalCakes << endl;
  }

  return 0;
}