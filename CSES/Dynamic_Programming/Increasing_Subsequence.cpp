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

void update(vector<int> &sorted, int val)
{
  int min = 0, max = sorted.size() - 1;
  if (sorted.front() >= val)
  {
    sorted.front() = val;
    return;
  }

  while (min + 1 < max)
  {
    int mid = (min + max) / 2;

    if (sorted.at(mid) < val)
    {
      min = mid;
    }
    else if (sorted.at(mid) > val)
    {
      max = mid;
    }
    else
    {
      return;
    }
  }
  sorted.at(max) = val;
}

int main()
{
  fast_io;
  int n;
  cin >> n;

  vector<int> nums(n);
  for (auto &i : nums)
  {
    cin >> i;
  }

  vector<int> sorted;
  sorted.push_back(nums.at(0));
  for (int i = 1; i < n; i++)
  {
    if (nums.at(i) > sorted.back())
    {
      sorted.push_back(nums.at(i));
    }
    else
    {
      update(sorted, nums.at(i));
    }
  }

  cout << sorted.size() << endl;
  // for (int i : sorted)
  // {
  //   cout << i << " ";
  // }
  // cout << endl;
  return 0;
}
