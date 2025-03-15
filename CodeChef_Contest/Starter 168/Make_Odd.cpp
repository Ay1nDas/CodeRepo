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
    string b1, b2;
    cin >> b1 >> b2;

    if (b1 != b2)
    {
      cout << "YES" << endl;
    }
    else
    {
      int oneCount = 0;
      for (int i = 0; i < n; i++)
      {
        if (b1.at(i) == '1')
        {
          oneCount++;
        }
      }
      if (oneCount % 2 == 1)
      {
        cout << "YES" << endl;
      }
      else
      {
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}