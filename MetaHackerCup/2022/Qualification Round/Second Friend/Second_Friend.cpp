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

  ifstream infile("second_friend_input.txt");
  ofstream outfile("second_friend_output.txt");
  fast_io;
  int T;
  infile >> T;
  for (int test_case = 1; test_case <= T; test_case++)
  {
    outfile << "Case #" << test_case << ": ";

    int r, c;
    infile >> r >> c;
    vector<vector<char>> field(r, vector<char>(c));

    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        infile >> field.at(i).at(j);
      }
    }

    if (r == 1 || c == 1)
    {
      bool isPoss = true;
      for (int i = 0; i < r; i++)
      {
        for (int j = 0; j < c; j++)
        {
          if (field.at(i).at(j) == '^')
            isPoss = false;
        }
      }
      if (isPoss)
      {
        outfile << "Possible" << endl;
        for (int i = 0; i < r; i++)
        {
          for (int j = 0; j < c; j++)
          {
            outfile << field.at(i).at(j);
          }
          outfile << endl;
        }
      }
      else
      {
        outfile << "Impossible" << endl;
      }
    }
    else
    {
      outfile << "Possible" << endl;
      for (int i = 0; i < r; i++)
      {
        for (int j = 0; j < c; j++)
        {
          outfile << '^';
        }
        outfile << endl;
      }
    }
  }

  return 0;
}