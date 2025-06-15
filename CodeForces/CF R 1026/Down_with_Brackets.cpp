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
    string str;
    cin >> str;

    bool isPossible = false;

    int brkt_cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {
      char c = str.at(i);
      if (c == '(')
        brkt_cnt++;
      else
        brkt_cnt--;

      if (brkt_cnt == 0 && i + 1 < str.length())
      {
        isPossible = true;
        break;
      }
    }
    cout << (isPossible ? "YES" : "NO") << endl;
  }

  return 0;
}