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

    for (int i = 0; i < n; i++)
      cin >> arr.at(i);

    bool isPoss = true;
    int l = 0, r = n - 1;
    for (int i = 1; i <= n; i++)
    {
      if (arr.at(l) == i)
        l++;
      else if (arr.at(r) == i)
        r--;
      else
        isPoss = false;
    }

    cout << (isPoss ? "YES" : "NO") << endl;
  }

  return 0;
}