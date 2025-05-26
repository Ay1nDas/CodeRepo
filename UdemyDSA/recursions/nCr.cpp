// Pascal's triangle
//        1             0C0
//       1  1           1Cr
//      1  2  1         2Cr
//     1  3  3  1       3Cr
//    1  4  6  4  1     4Cr
//  1  5  10 10  5  1    5Cr

#include <bits/stdc++.h>
using namespace std;

int combination(int n, int r)
{
  if (r == 0 || n == r)
  {
    return 1;
  }
  else
  {
    return combination(n - 1, r - 1) + combination(n - 1, r);
  }
}

int main()
{
  cout << combination(5, 2) << endl;
  return 0;
}