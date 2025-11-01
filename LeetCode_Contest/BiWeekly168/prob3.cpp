#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long minOperations(vector<int> &nums1, vector<int> &nums2)
  {
    long long oppCnt = 0;
    long long lastDigOppCnt = static_cast<long long>(abs(nums2.back() - nums1.at(0)));
    for (int i = 0; i < nums1.size(); i++)
    {
      oppCnt += static_cast<long long>(abs(nums1.at(i) - nums2.at(i)));

      long long currLastDig = static_cast<long long>(min(abs(nums2.back() - nums1.at(i)), abs(nums2.back() - nums2.at(i))));
      if (nums2.back() > nums1.at(i) && nums2.back() < nums2.at(i))
      {
        currLastDig = 0;
      }
      else if (nums2.back() < nums1.at(i) && nums2.back() > nums2.at(i))
      {
        currLastDig = 0;
      }

      lastDigOppCnt = static_cast<long long>(min(lastDigOppCnt, currLastDig));
    }

    return oppCnt + lastDigOppCnt + 1;
  }
};

int main()
{
  return 0;
}