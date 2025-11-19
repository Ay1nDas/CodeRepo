#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define mod 1000000007

int main()
{

  ifstream infile("deciding_points_input.txt");
  ofstream outfile("deciding_points_output.txt");
  fast_io;
  int T;
  infile >> T;
  for (int test_case = 1; test_case <= T; test_case++)
  {
    outfile << "Case #" << test_case << ": ";

    int n, m;
    infile >> n >> m;

    if (n >= m && n <= 2 * m - 2)
    {
      outfile << "YES" << endl;
    }
    else if (n >= 2 * m && n % 2 == 0)
    {
      outfile << "YES" << endl;
    }
    else
    {
      outfile << "NO" << endl;
    }
  }

  return 0;
}