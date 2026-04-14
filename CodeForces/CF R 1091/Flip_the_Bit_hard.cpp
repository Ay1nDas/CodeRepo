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

    vector<int> bits(n), sp_idx(k);
    for(auto &i : bits) {
      cin >> i;
    }
    for(auto &i : sp_idx) {
      cin >> i;
    }

    bits.insert(bits.begin(), bits.at(sp_idx.front() - 1));
    bits.push_back(bits.at(sp_idx.front()));

    vector<int> opps;
    int curr_op = 0;
    for(int i = 1, j = 0; i < bits.size(); i++) {
      if(bits.at(i) != bits.at(i - 1)) {
        // cout << bits.at(i) << " " << bits.at(i - 1) << " i: " << i << endl;
        curr_op++;
      }

      if(j < sp_idx.size() && i == sp_idx.at(j)) {
        opps.push_back(curr_op);
        curr_op = 0;
        j++;
      }
    }
    opps.push_back(curr_op);

    // for(auto op : opps) {
    //   cout << op << " ";
    // }
    // cout << endl;

    int reserve = 0;
    int lft_opp = 0;
    for(int i = 0; i < opps.size(); i++) {
      if(reserve > opps.at(i)) {
        reserve -= opps.at(i);
      } else {
        reserve = opps.at(i) - reserve;
        lft_opp += reserve;
      }
    }

    int rht_opp = 0;
    for(int i = opps.size() - 1; i >= 0; i--) {
      if(reserve > opps.at(i)) {
        reserve -= opps.at(i);
      } else {
        reserve = opps.at(i) - reserve;
        rht_opp += reserve;
      }
    }

    cout << "Ans: " << max(lft_opp, rht_opp) << endl;
    // cout << max(lft_opp, rht_opp) << endl;
  }

  return 0;
}