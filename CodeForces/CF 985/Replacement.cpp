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
    string s, r;
    cin >> s >> r;

    int r_index{0};
    for (int i = 0; i + 1 < n && n > 1; i++)
    {
      // if (i - 1 > 0 && s[i] != s[i - 1])
      // {
      //   s.at(i) = r.at(r_index++);
      //   s.erase(i - 1, 1);

      //   n--;
      //   i -= 2;
      // }
      if (s[i] != s[i + 1])
      {
        s.at(i) = r.at(r_index++);
        s.erase(i + 1, 1);
        i -= 2;
        if (i < -1)
          i = -1;
        n--;
      }
    }

    // cout << "R_INDEX: " << r_index << endl;

    if (r_index == r.size())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}