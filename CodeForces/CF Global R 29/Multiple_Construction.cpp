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

    vector<int> res(n * 2);

    res.at(0) = n;
    res.at(n) = n;
    for (int i = n + 1; i < 2 * n; i++)
      res.at(i) = i - n;

    for (int i = n - 1; i > 0; i--)
      res.at(i) = n - i;

    for (auto i : res)
      cout << i << " ";
    cout << endl;
  }

  return 0;
}