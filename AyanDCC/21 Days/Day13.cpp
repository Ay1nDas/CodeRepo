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

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
      cin >> a.at(i);
    for (int i = 0; i < m; i++)
      cin >> b.at(i);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> left_diff(n), right_diff(n);

    for (int i = 0; i < n; i++)
    {
      right_diff.at(i) = abs(a.at(i) - b.at(m - 1 - i));
      left_diff.at(n - 1 - i) = abs(a.at(n - 1 - i) - b.at(i));
    }

    ll value{0};

    for (int i = 0; i < n; i++)
    {
      if (right_diff.at(i) > left_diff.at(i))
        value += right_diff.at(i);
      else
        value += left_diff.at(i);
    }

    cout << value << endl;
  }

  return 0;
}