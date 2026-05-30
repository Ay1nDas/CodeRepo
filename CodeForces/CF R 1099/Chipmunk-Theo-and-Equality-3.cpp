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

    unordered_map<int, pair<int, int>> reachable;
    for(int elem : arr) {
      reachable[elem].first++;
      int curr_opp = 0;

      if(elem == 1) {
        reachable[2].first++;
        reachable[2].second++;
      }

      while(elem != 1) {
        if(elem % 2) {
          elem++;
        } else {
          elem /= 2;
        }
        curr_opp++;
        reachable[elem].first++;
        reachable[elem].second+= curr_opp;
      }
    }

    int min_opp = INT_MAX;
    for(auto pair : reachable) {
      if(pair.second.first == arr.size()) {
        min_opp = min(min_opp, pair.second.second);
      }
    }

    cout << min_opp << endl;
  }

  return 0;
}