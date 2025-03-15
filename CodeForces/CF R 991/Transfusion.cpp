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
    // ll total_sum{0};
    double even_sum{0}, odd_sum{0};

    for (int i = 0; i < n; i++)
    {
      int num;
      cin >> num;
      // total_sum += num;

      if (i % 2 == 0)
        even_sum += num;
      else
        odd_sum += num;
    }

    // cout << even_sum << endl
    //      << odd_sum << endl
    //      << endl;

    if (n % 2)
    {
      odd_sum /= (n / 2);
      even_sum /= (n / 2 + 1);
    }
    else
    {
      odd_sum /= (n / 2);
      even_sum /= (n / 2);
    }

    cout << ((even_sum == odd_sum && fmod(even_sum, 1.0) == 0.0) ? "YES" : "NO") << endl;
  }

  return 0;
}