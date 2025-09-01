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

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr.at(i);

    if (n == 1)
    {
      cout << arr.at(0) + k << endl;
      continue;
    }

    if (k % 2 != 0)
    {
      for (int i = 0; i < n; i++)
        arr.at(i) += (arr.at(i) % 2 ? k : 0);
    }
    else if (k % 3 != 0)
    {
      for (int i = 0; i < n; i++)
      {
        if (arr.at(i) % 3 == 0)
          continue;

        int rem = arr.at(i) % 3;
        int left = k % 3;
      }
    }
    else
    {
      for (int i = 0; i < n; i++)
      {
        if (arr.at(i) % 7 == 0)
          continue;

        int cnt = k;
        while (cnt-- && arr.at(i) % 7 != 0)
          arr.at(i) += k;
      }
    }

    // cout << "ans:" << endl;
    for (auto i : arr)
      cout << i << " ";
    cout << endl;
  }

  return 0;
}