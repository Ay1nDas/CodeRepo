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
    string number;
    cin >> number;

    for (int i = 1; i < number.length(); i++)
    {
      if (i > 0 && number.at(i - 1) < number.at(i) - 1)
      {
        char tmp = number.at(i - 1);
        number.at(i - 1) = number.at(i) - 1;
        number.at(i) = tmp;
        i -= 2;
      }
    }

    cout << number << endl;
  }

  return 0;
}