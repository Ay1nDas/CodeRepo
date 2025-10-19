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

  ifstream infile("snake_scales_chapter_1_input.txt");
  ofstream outfile("snake_scales_chapter_1_output.txt");
  fast_io;
  int T;
  infile >> T;
  for (int test_case = 1; test_case <= T; test_case++)
  {
    outfile << "Case #" << test_case << ": ";
    int n;
    infile >> n;

    int preNum = 0;
    infile >> preNum;

    int max_val = 0;
    for (int i = 1; i < n; i++)
    {
      int num;
      infile >> num;

      max_val = max(abs(num - preNum), max_val);
      preNum = num;
    }

    outfile << max_val << endl;
  }

  return 0;
}