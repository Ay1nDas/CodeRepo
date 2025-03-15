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
    string x, y;
    cin >> x >> y;

    int make_great{1};

    for (int i = 0; i < x.length(); i++)
    {
      if (make_great && x.at(i) != y.at(i))
      {
        make_great--;
        if (x.at(i) > y.at(i))
        {
          char tmp = x.at(i);
          x.at(i) = y.at(i);
          y.at(i) = tmp;
        }
      }
      else if (!make_great && x.at(i) < y.at(i))
      {
        char tmp = x.at(i);
        x.at(i) = y.at(i);
        y.at(i) = tmp;
      }
    }

    cout << x << endl
         << y << endl;
  }

  return 0;
}