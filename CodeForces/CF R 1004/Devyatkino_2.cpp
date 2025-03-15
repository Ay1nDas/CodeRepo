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
    nums = '0' + nums;

    int val = nums.at(nums.length() - 1) - '0';
    val -= 7;
    if (val < 0)
      val += 10;
    int min_value = val;

    // bool before_zero = true;

    for (int i = nums.length() - 2; i >= 0; i--)
    {
      int part_num = stoi(nums.substr(i + 1));

      if (nums.at(i) == '8' && part_num == 0)
        min_value = min(1, min_value);

      val = 7 - (nums.at(i) - '0');
      if (val < 0)
        val += 10;

      if (val > part_num)
        val += 1;

      min_value = min(val, min_value);
    }

    cout << min_value << endl;
  }

  return 0;
}