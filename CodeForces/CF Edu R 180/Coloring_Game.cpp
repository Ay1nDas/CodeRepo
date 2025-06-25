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
    int total_cnt = 0;

    for (int i = 0; i < n; i++)
      cin >> nums.at(i);

    int max_val = nums.at(n - 1);

    for (int i = 0; i < n - 2; i++)
    {
      if (nums.at(i) >= max_val)
      {
        total_cnt += (n - i - 1) * (n - i - 2) / 2;
        continue;
      }

      for (int j = i + 1; j < n - 1; j++)
      {
        int curr_sum = nums.at(i) + nums.at(j);

        if (curr_sum > max_val)
        {
          total_cnt += n - j - 1;
        }
        else
        {
          for (int k = j + 1; k < n; k++)
          {
            if (curr_sum > nums.at(k) && curr_sum + nums.at(k) > max_val)
              total_cnt++;
          }
        }
      }
    }

    cout << total_cnt << endl;
  }

  return 0;
}