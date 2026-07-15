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
  int n;
  cin >> n;
  string s;
  cin >> s;

  int val = 0;
  for (auto &c : s) {
    val += c - 'a' + 1;
  }

  cout << val << endl;

  return 0;
}