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
    string nums;
    cin >> nums;

    int val = nums.at(nums.length() - 1) - '0';
    val -= 7;
    if (val < 0)
      val += 10;
    int min_value = val;

    bool before_zero = true;

    for (int i = nums.length() - 1; i >= 0; i++)
    {
      int value = 0;
      if (before_zero && nums.at(i) == '8')
      {
        min_value = min(1, min_value);
      }
      else if (!before_zero)
      {
      }

      if (before_zero && nums.at(i) != '0')
        before_zero = false;
    }
  }

  return 0;
}