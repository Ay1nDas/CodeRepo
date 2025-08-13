#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> popcountDepth(vector<long long> &nums, vector<vector<long long>> &queries)
  {

    vector<int> pops(nums.size());
    int idx = 0;

    for (auto n : nums)
    {
      int popCnt = 0;
      while (n != 1)
      {
        popCnt++;
        int oneCnt = 0;
        while (n)
        {
          oneCnt += (n % 2 ? 1 : 0);
          n /= 2;
        }
        n = oneCnt;
      }

      pops.at(idx++) = popCnt;
    }

    vector<vector<int>> kPops(pops.size(), vector<int>(6));
    if (pops.at(0) <= 5)
      kPops.at(0).at(pops.at(0)) = 1;

    for (int i = 1; i < pops.size(); i++)
    {
      for (int j = 0; j < 6; j++)
        kPops.at(i).at(j) = kPops.at(i - 1).at(j);

      if (pops.at(i) <= 5)
        kPops.at(i).at(pops.at(i)) += 1;
    }

    for (int i = 0; i < pops.size(); i++)
    {
      cout << kPops.at(i).at(0) << " ";
      cout << kPops.at(i).at(1) << " ";
      cout << kPops.at(i).at(2) << " ";
      cout << kPops.at(i).at(3) << " ";
      cout << kPops.at(i).at(4) << " ";
      cout << kPops.at(i).at(5) << endl;
    }

    vector<int> retVec;
    for (auto q : queries)
    {
      if (q.at(0) == 1)
      {
        if (q.at(1))
          retVec.push_back(kPops.at(q.at(2)).at(q.at(3)) - kPops.at(q.at(1) - 1).at(q.at(3)));
        else
          retVec.push_back(kPops.at(q.at(2)).at(q.at(3)));
      }
      else
      {
        int val = q.at(2);
        int popCnt = 0;
        while (val != 1)
        {
          popCnt++;
          int oneCnt = 0;
          while (val)
          {
            oneCnt += (val % 2 ? 1 : 0);
            val /= 2;
          }
          val = oneCnt;
        }
        int toChange = pops.at(q.at(1));

        for (int i = q.at(1); i < pops.size(); i++)
        {
          kPops.at(i).at(toChange)--;
          if (popCnt <= 5)
            kPops.at(i).at(popCnt)++;
        }
      }
    }

    return retVec;
  }
};

int main()
{
  return 0;
}