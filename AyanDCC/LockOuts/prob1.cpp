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
    vector<int> vec(3);
    cin >> vec.at(0);
    cin >> vec.at(1);
    cin >> vec.at(2);

    sort(vec.begin(), vec.end());
    cout << vec.at(1) << endl;
  }

  return 0;
}