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

    int one_count = 0;
    for (int i = 0; i < str.size(); i++)
    {
      if (str.at(i) == '1')
        one_count++;
    }
    cout << one_count << endl;
  }

  return 0;
}