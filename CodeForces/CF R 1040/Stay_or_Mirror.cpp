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

    for (int i = 0; i < n; i++)
    {
      cin >> nums.at(i);
    }

    for (int i = n - 1; i > 0; i--)
    {
      int front = 0, back = 0;

      for (int j = 0; j < i; j++)
      {
        if (nums.at(j) > nums.at(i))
          front++;
      }

      int mirror = 2 * n - nums.at(i);
      for (int j = i + 1; j < n; j++)
      {
        if (mirror > nums.at(j))
          back++;
      }

      if (back <= front)
      {
        nums.at(i) = mirror;
      }
    }

    ll total_cnt = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (nums.at(i) > nums.at(j))
          total_cnt++;
      }
    }

    // for (auto num : nums)
    // {
    //   cout << num << " ";
    // }
    // cout << endl;

    cout << total_cnt << endl;
  }

  return 0;
}

//  9
//  3 4 5 1 6 7 2 8 9