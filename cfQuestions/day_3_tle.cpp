#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define allr(x) (x).rbegin(), (x).rend()
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
    for(auto &i : arr) {
      cin >> i;
    }

    sort(allr(arr));

    if(arr.size() < 2) {
      cout << -1 << endl;
    } else {
      cout << arr.at(1) << endl;
    }
  }

  return 0;
}