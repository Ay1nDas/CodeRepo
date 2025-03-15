#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
  long long numberOfSubsequences(vector<int> &nums)
  {
    long long count = 0;

    for (int i = 0; i < nums.size(); i++)
      for (int j = i + 2; j < nums.size(); j++)
        for (int k = j + 2; k < nums.size(); k++)
          for (int l = k + 2; l < nums.size(); l++)
            if (nums.at(i) * nums.at(k) == nums.at(j) * nums.at(l))
              count++;

    return count;
  }
};

int main()
{
}