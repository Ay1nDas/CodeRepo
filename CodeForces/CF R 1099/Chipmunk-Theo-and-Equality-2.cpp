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
    unordered_set<int> unq;
    for(auto &i : arr) {
      cin >> i;
      unq.insert(i);
    }

    unordered_map<int, int> reachable;
    for(int elem : unq) {
      reachable[elem]++;
      while(elem != 1) {
        if(elem % 2) {
          elem++;
        } else {
          elem /= 2;
        }
        reachable[elem]++;
      }
    }
    int max_reach = 1;
    for(auto pair : reachable) {
      if(pair.second == unq.size()) {
        max_reach = max(max_reach, pair.first);
      }
    }
    if(max_reach <= 2) {
      max_reach = 2;
    } else if(max_reach % 2 == 0 && reachable[max_reach - 1] == unq.size()) {
      max_reach--;
    }

    int opp_cnt = 0;
    for(auto i : arr) {
      while(i != max_reach) {
        if (i % 2) {
          i++;
        } else {
          i /= 2;
        }
        opp_cnt++;
      }
    }

    cout << opp_cnt << endl;
  }

  return 0;
}