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
    map<int, int, greater<int>> freq;

    for(auto &i : arr) {
      cin >> i;
      freq[i]++;
    }

    vector<int> ret_arr;
    ret_arr.reserve(n);
    bool haveElem = true;

    while(haveElem) {
      haveElem = false;
      for (auto &[key, value] : freq) {
        // cout << key << " " << value << endl;
        if (value > 0) {
          haveElem = true;
          ret_arr.push_back(key);
          value--;
        }
      }
    }

    for (auto &i : ret_arr) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}