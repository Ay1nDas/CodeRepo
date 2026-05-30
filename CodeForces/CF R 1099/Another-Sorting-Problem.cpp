#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
    for (auto &i : arr) {
      cin >> i;
    }

    int local_max = arr.at(0);
    int dip = 0;
    for(int i = 1; i < n; i++) {
      local_max = max(local_max, arr.at(i));
      dip = max(dip, local_max - arr.at(i));
    }

    for(int i = 1; i < n; i++) {
      if(arr.at(i) < arr.at(i-1)) {
        arr.at(i) += dip;
      }
    }

    bool isPoss = true;
    for(int i = 1; i < n; i++) {
      if(arr.at(i) < arr.at(i-1)) {
        isPoss = false;
        break;
      }
    }

    cout << (isPoss ? "YES" : "NO") << endl;
  }

  return 0;
}