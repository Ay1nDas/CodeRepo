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

    int matches = 0;
    int win = n, lose = 0;
    while (win > 1 || lose > 1)
    {
      int newLose = win / 2;
      matches += win / 2;
      win = win / 2 + win % 2;

      matches += lose / 2;
      lose = lose / 2 + lose % 2 + newLose;
    }

    cout << matches + 1 << endl;
  }

  return 0;
}