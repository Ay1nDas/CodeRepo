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

    bool isPossible = false;
    for (int i = 1; i < n; i++)
    {
      if (abs(arr.at(i - 1) - arr.at(i)) < min(arr.at(i), arr.at(i - 1)))
      {
        isPossible = true;
        break;
      }
    }

    cout << (isPossible ? "YES" : "NO") << endl;
  }

  return 0;
}