#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minSensors(int n, int m, int k)
  {
    int coverage = k * 2 + 1;

    int sensors = 0;

    sensors += n / coverage;
    n -= coverage * (n / coverage);
    sensors += n > 0 ? 1 : 0;

    sensors += m / coverage;
    m -= coverage * (m / coverage);
    sensors += m > 0 ? 1 : 0;

    return sensors;
  }
};

int main()
{
  return 0;
}