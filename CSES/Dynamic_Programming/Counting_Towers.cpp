#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define all(x) (x).begin(), (x).end()
int mod = 1000000007;

int main()
{

  fast_io;
  int T;
  cin >> T;
  vector<ll> inputs(T);
  ll maxInput = INT_MIN;
  for (auto &i : inputs)
  {
    cin >> i;
    maxInput = max(maxInput, i);
  }

  vector<vector<ll>> towers(maxInput + 1, vector<ll>(2));
  towers.at(1).at(0) = 1;
  towers.at(1).at(1) = 1;

  for (int i = 2; i < maxInput + 1; i++)
  {
    towers.at(i).at(0) = (4 * towers.at(i - 1).at(0) + towers.at(i - 1).at(1)) % mod;
    towers.at(i).at(1) = (towers.at(i - 1).at(0) + 2 * towers.at(i - 1).at(1)) % mod;
  }

  for (auto &i : inputs)
    cout << (towers.at(i).at(0) + towers.at(i).at(1)) % mod << endl;

  return 0;
}