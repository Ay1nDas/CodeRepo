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
    int fst = (n + 1) / 2;
    int snd = fst + 1;

    while (fst > 0)
    {
      cout << fst-- << " ";
      if (snd <= n)
      {
        cout << snd++ << " ";
      }
    }
    cout << endl;
  }

  return 0;
}