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
    int n, k;
    cin >> n >> k;

    vector <int> arr(n);
    for(auto &i : arr) {
      cin >> i;
    }

    int sp_idx;
    cin >> sp_idx;
    sp_idx--;

    int curr_val = arr.at(sp_idx);
    int lft = 0, rht = 0;
    for(int i = sp_idx - 1; i >= 0; i--) {
      if(arr.at(i) != arr.at(i + 1)) {
        lft++;
      }
    }

    if(arr.front() != arr.at(sp_idx)) {
      lft++;
    }

    for(int i = sp_idx + 1; i < arr.size(); i++) {
      if (arr.at(i) != arr.at(i - 1)) {
        rht++;
      }
    }

    if(arr.back() != arr.at(sp_idx)) {
      rht++;
    }

    // cout << "ANS: " << max(lft, rht) << endl;
    cout << max(lft, rht) << endl;
  }

  return 0;
}