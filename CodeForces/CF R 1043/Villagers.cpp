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
  while (T--)
  {
    int n;
    cin >> n;

    vector<int> grump(n);
    for (int i = 0; i < n; i++)
    {
      cin >> grump.at(i);
    }

    sort(grump.rbegin(), grump.rend());
    ll total_emeralds = 0;

    for (int i = 0; i < n; i += 2)
      total_emeralds += grump.at(i);

    cout << total_emeralds << endl;
  }

  return 0;
}