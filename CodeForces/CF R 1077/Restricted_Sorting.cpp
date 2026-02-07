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
    vector<int> nums(n);
    for (auto &i : nums)
    {
      cin >> i;
    }

    vector<int> sorted = nums;
    sort(all(sorted));

    int min_num = sorted.front(), max_num = sorted.back();
    int max_k = INT_MAX;
    for (int i = 0; i < n; i++)
    {
      if (nums.at(i) == sorted.at(i))
      {
        continue;
      }

      max_k = min(max_k, max(nums.at(i) - min_num, max_num - nums.at(i)));
    }

    // cout << "\nANS: " << max_k << endl;
    cout << (max_k == INT_MAX ? -1 : max_k) << endl;
  }

  return 0;
}