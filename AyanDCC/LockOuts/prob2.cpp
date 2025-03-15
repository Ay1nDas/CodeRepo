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
    string str;
    cin >> str;

    int max_c = 0;

    for (auto c : str)
    {
      if (c > max_c)
      {
        max_c = c;
      }
    }
    cout << max_c - 'a' + 1 << endl;
  }

  return 0;
}