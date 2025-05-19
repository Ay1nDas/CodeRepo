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

class Solution
{
public:
  int smallestIndex(vector<int> &nums)
  {
    for (int i = 0; i < nums.size(); i++)
    {
      int sum = 0;
      int num = nums.at(i);
      while (num)
      {
        sum += num % 10;
        num /= 10;
      }

      if (sum == i)
      {
        return i;
      }
    }
    return -1;
  }
};

int main()
{
  return 0;
}