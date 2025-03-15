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
    string word;
    cin >> word;

    bool isOne = false;
    for (int i = 0; i + 1 < word.length(); i++)
    {
      if (word.at(i) == word.at(i + 1))
      {
        isOne = true;
        break;
      }
    }

    cout << (isOne ? 1 : word.length()) << endl;
  }

  return 0;
}