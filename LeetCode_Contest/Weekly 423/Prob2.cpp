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

int maxIncreasingSubarrays(vector<int> &nums)
{

  int before_count{1}, after_count{0};
  int neg_found{1};
  int pre_value{nums.at(0)};
  int max_count{0};

  for (int i = 1; i < nums.size(); i++)
  {
    int value{nums.at(i)};
    nums.at(i) -= pre_value;
    pre_value = value;

    // cout << nums.at(i) << " ";

    if (nums.at(i) > 0 && neg_found > 0)
      before_count++;
    else if (nums.at(i) > 0 && neg_found == 0)
      after_count++;
    else if (neg_found > 0)
    {
      neg_found--;
      after_count++;
    }
    else
    {
      neg_found = 1;
      before_count = 1;
      after_count = 0;
    }
    cout << before_count << endl
         << after_count << endl
         << neg_found << endl
         << endl;

    if (max_count < min(before_count, after_count))
      max_count = min(before_count, after_count);
    else if (max_count < max(before_count, after_count) / 2)
      max_count = max(before_count, after_count) / 2;
  }
  return max_count;
}

int main()
{
  return 0;
}