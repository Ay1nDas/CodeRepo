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
    int n = 0;
    cin >> n;

    unordered_map <int, int> use;
    int pre_val = 1;
    cout << 1 << " ";
    if(n <= 1) {continue;}

    int curr_val = 2;
    for(int i = 1; i < n; i++) {
      while(use[curr_val] == 1) {
        curr_val++;
      }
      use[curr_val + pre_val] = 1;
      pre_val = curr_val;
      cout << curr_val++ << " ";
    }

    cout << endl;
  }

  return 0;
}