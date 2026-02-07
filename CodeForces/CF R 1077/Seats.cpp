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
    str = "0" + str + "0";

    int cnt = 0;
    int min_seat = 0;
    for (int i = 0; i < str.size(); i++)
    {
      if (str.at(i) == '1')
      {
        min_seat += cnt / 3;
        min_seat++;
        // cout << min_seat << endl;
        cnt = 0;
      }
      else
      {
        cnt++;
      }
    }
    min_seat += cnt / 3;

    cout << min_seat << endl;
  }

  return 0;
}