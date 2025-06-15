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

    vector<int> chests(n);

    for (int i = 0; i < n; i++)
      cin >> chests.at(i);
    sort(chests.rbegin(), chests.rend());

    int coin_taken{0};
    for (int i = 0; i < n; i++)
    {
      coin_taken += chests.at(i);
      if (i + 1 < n && k - coin_taken < chests.at(i + 1))
        break;
    }

    cout << k - coin_taken << endl;
  }

  return 0;
}