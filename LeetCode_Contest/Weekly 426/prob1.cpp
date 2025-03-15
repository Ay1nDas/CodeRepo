#include <iostream>
using namespace std;

class Solution
{
public:
  int smallestNumber(int n)
  {
    int reqd_num{1};
    while (n)
    {
      reqd_num *= 2;
      n /= 2;
    }
    return reqd_num - 1;
  }
};

int main()
{
}
