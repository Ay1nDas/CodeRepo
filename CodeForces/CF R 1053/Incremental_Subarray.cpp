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

    vector<int> a(m);
    for (auto &i : a)
      cin >> i;

    bool notInc = false;
    for (int i = 1; i < m; i++)
    {
      if (a.at(i) - a.at(i - 1) != 1)
      {
        notInc = true;
        break;
      }
    }

    // cout << "ANs: ";
    if (notInc)
    {
      cout << 1 << endl;
    }
    else
    {
      cout << n - a.back() + 1 << endl;
    }
  }

  return 0;
}