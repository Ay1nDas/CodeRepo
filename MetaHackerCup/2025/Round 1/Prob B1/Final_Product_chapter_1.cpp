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

  ifstream infile("final_product_chapter_1_input.txt");
  ofstream outfile("final_product_chapter_1_output.txt");
  fast_io;
  int T;
  infile >> T;
  for (int test_case = 1; test_case <= T; test_case++)
  {
    outfile << "Case #" << test_case << ": ";
    int n, a, b;
    infile >> n >> a >> b;

    for (int i = 0; i < 2 * n - 1; i++)
    {
      outfile << 1 << " ";
    }
    outfile << b << endl;
  }

  return 0;
}