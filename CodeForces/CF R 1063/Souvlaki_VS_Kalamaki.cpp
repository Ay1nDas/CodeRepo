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

    vector<int> arr(n);
    for (auto &i : arr)
    {
      cin >> i;
    }

    sort(all(arr));
    bool isPoss = true;

    // for (auto i : arr)
    // {
    //   cout << i << " ";
    // }
    // cout << endl;

    for (int i = 1; i < n - 1; i += 2)
    {
      if (arr.at(i) != arr.at(i + 1))
      {
        isPoss = false;
      }
    }

    cout << (isPoss ? "YES" : "NO") << endl;
  }

  return 0;
}