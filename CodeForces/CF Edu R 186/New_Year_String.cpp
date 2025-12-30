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

    string prefix = "202";
    string str;
    cin >> str;

    bool have6 = false;
    bool Nohave5 = true;
    for (int i = 0; i + 3 < n; i++)
    {
      if (str.at(i) == '2' && str.at(i + 1) == '0' && str.at(i + 2) == '2')
      {
        if (str.at(i + 3) == '5')
        {
          Nohave5 = false;
        }
        else if (str.at(i + 3) == '6')
        {
          have6 = true;
        }
      }
    }

    if (have6 || Nohave5)
    {
      cout << 0 << std::endl;
    }
    else
    {
      cout << 1 << std::endl;
    }
  }

  return 0;
}