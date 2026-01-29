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
    for(auto &i : arr) {
      cin >> i;
    }

    int first = -1, second = -1;
    for(int i = 0; i < n; i++) {
      if (first < arr[i]) {
        second = first;
        first = arr[i];
      } else if (second < arr[i]) {
        second = arr[i];
      }
    }

    cout << second << endl;
  }

  return 0;
}