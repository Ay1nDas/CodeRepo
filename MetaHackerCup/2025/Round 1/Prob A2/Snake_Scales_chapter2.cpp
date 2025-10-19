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

  ifstream infile("snake_scales_chapter_2_input.txt");
  ofstream outfile("snake_scales_chapter_2_output.txt");
  fast_io;
  int T;
  infile >> T;
  for (int test_case = 1; test_case <= T; test_case++)
  {
    outfile << "Case #" << test_case << ": ";
    ll n;
    infile >> n;

    vector<ll> levels(n + 2);
    vector<ll> ladderPre(n + 2);
    vector<ll> ladderPost(n + 2);
    for (int i = 1; i <= n; i++)
    {
      infile >> levels.at(i);
    }

    for (int i = 1; i <= n; i++)
    {
      ll groundLadder = levels.at(i);
      ll preLadder = max(abs(levels.at(i) - levels.at(i - 1)), ladderPre.at(i - 1));
      ladderPre.at(i) = min(preLadder, groundLadder);
    }

    for (int i = n; i >= 1; i--)
    {
      ll groundLadder = levels.at(i);
      ll postLadder = max(abs(levels.at(i) - levels.at(i + 1)), ladderPost.at(i + 1));
      ladderPost.at(i) = min(postLadder, groundLadder);
    }

    ll max_ladder = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
      // cout << ladderPre.at(i) << " " << ladderPost.at(i) << endl;

      ll curr_ladder = min(ladderPre.at(i), ladderPost.at(i));
      max_ladder = max(curr_ladder, max_ladder);
    }

    outfile << max_ladder << endl;
  }

  return 0;
}