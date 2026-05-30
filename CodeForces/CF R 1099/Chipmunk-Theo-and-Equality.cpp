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

    int min_val = INT_MAX;
    for(auto &i : arr) {
      cin >> i;
      min_val = min(i, min_val);
    }

    min_val += (min_val % 2 ? 1 : 0);
    int ops = 0;
    while(true) {
      int local_min = min_val;
      bool all_same = true;
      for(int i = 0; i < n; i++) {
        if (min_val - arr.at(i) < 0) {
          all_same = false;
          break;
        }
      }

      if(all_same) break;

      for(int i = 0; i < n; i++) {
        while(arr.at(i) > min_val) {
          if(arr.at(i) % 2) {
            arr.at(i)++;
          } else {
            arr.at(i) /= 2;
          }
          ops++;
        }
        local_min = min(local_min, arr.at(i));
      }

      min_val = local_min + (local_min % 2 ? 1 : 0);
    }

    int even = 0, odd = 0;
    int even_val = 0, odd_val = 0;
    for(auto &i : arr) {
      if(i % 2) {
        odd++;
        odd_val = i;
      } else {
        even++;
        even_val = i;
      }
    }

    if(even_val / 2 == odd_val) {
      cout << ops + min(even, odd) << endl;
    } else if(even_val / 2 + 1 == odd_val){
      cout << ops + min(even * 2, odd) << endl;
    } else {
      cout << ops + odd << endl;
    }
  }

  return 0;
}