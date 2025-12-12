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

    int lft = 0, rht = n - 1;
    while (lft <= rht && (str.at(lft) == '0' || str.at(rht) == '0'))
    {
      if (str.at(lft) == '0')
      {
        lft++;
      }
      else if (str.at(rht) == '0')
      {
        rht--;
      }
    }

    int prevOne = -1;
    int MaxleftOne = INT_MAX;
    if (lft <= rht)
      MaxleftOne = lft + n - rht - 1;

    for (int i = 0; i < n; i++)
    {
      if (str.at(i) == '1')
      {
        if (prevOne == -1)
        {
          prevOne = i;
          continue;
        }
        else
        {
          MaxleftOne = max(MaxleftOne, i - prevOne - 1);
          prevOne = i;
        }
      }
    }

    cout << MaxleftOne << endl;
  }

  return 0;
}