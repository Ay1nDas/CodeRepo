//     -|-              |               |
//    --|--             |               |
//   ---|---            |               |
//  ----|----           |               |
// -----|-----          |               |

//      A               B               C

#include <bits/stdc++.h>
using namespace std;

void TOH(int n, char base, char supp, char dest)
{
  if (n > 0)
  {
    TOH(n - 1, base, dest, supp);
    cout << "Moving Top disk of " << base << " to " << dest << " using support " << supp << endl;
    TOH(n - 1, supp, base, dest);
  }
}

int main()
{
  TOH(3, '1', '2', '3');
  return 0;
}