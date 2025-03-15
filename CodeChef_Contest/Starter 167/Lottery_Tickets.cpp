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
    int n = 0;
    cin >> n;

    vector<int> nums(n);
    cin >> nums.at(0);
    int index = 0;

    for (int i = 1; i < n; i++)
    {
      cin >> nums.at(i);
      if (nums.at(i) < nums.at(0))
        index++;
    }

    sort(nums.begin(), nums.end());

    int count = 1;
    for (int i = 1; i < n; i++)
      if ((nums.at(i) - nums.at(i - 1)) % 2 == 0)
        count++;

    if (index > 0)
      count += (nums.at(index) - nums.at(index - 1) - 1) / 2;
    else
      count += nums.at(index) - 1;

    if (index + 1 < n)
      count += (nums.at(index + 1) - nums.at(index) - 1) / 2;
    else
      count += 1000000 - nums.at(index);

    cout << count << endl;
  }

  return 0;
}