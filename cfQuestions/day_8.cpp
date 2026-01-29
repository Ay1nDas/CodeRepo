//     -|-              |               |
//    --|--             |               |
//   ---|---            |               |
//  ----|----           |               |
// -----|-----          |               |

//      A               B               C

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
int mod = 1000000007;

void TOH(int n, char base, char supp, char dest)
{
  if (n > 0)
  {
    TOH(n - 1, base, dest, supp);
    cout << base << " " << dest << endl;
    TOH(n - 1, supp, base, dest);
  }
}

int main()
{

  fast_io;
  int n;
  cin >> n;

  cout << pow(2, n) - 1 << endl;

  TOH(n, 'A', 'B', 'C');
  return 0;

  return 0;
}