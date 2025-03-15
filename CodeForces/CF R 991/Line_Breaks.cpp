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
    int n, m;
    cin >> n >> m;

    int word_remaining = n;

    while (word_remaining--)
    {
      string word;
      cin >> word;

      if (m >= word.length())
        m -= word.length();
      else
        break;
    }

    cout << n - word_remaining - 1 << endl;

    while (word_remaining > 0 && word_remaining--)
    {
      string tmp;
      cin >> tmp;
      // cout << "tmp:" << tmp << endl;
    }
  }

  return 0;
}