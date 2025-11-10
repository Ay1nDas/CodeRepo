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
    int n, x;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
      cin >> arr.at(i);
    }

    cin >> x;

    int min_val = arr.at(0), max_val = arr.at(0);
    for (int i = 0; i < n; i++)
    {
      min_val = min(min_val, arr.at(i));
      max_val = max(max_val, arr.at(i));
    }

    if (min_val <= x && max_val >= x)
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