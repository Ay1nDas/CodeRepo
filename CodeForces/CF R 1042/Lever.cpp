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

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++)
      cin >> a.at(i);
    for (int i = 0; i < n; i++)
      cin >> b.at(i);

    int lesser = 0, greater = 0;
    for (int i = 0; i < n; i++)
    {
      if (a.at(i) < b.at(i))
        lesser += b.at(i) - a.at(i);
      else if (a.at(i) > b.at(i))
        greater += a.at(i) - b.at(i);
    }

    cout << max(greater, 0) + 1 << endl;
  }

  return 0;
}