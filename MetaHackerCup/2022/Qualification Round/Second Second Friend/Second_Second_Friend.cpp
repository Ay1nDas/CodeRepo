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

int dfs(vector<vector<char>> &field, int i, int j, int pre_i, int pre_j)
{
  if (field.at(i).at(j) == '#')
  {
    return 0;
  }
  else if (field.at(i).at(j) == '1' || field.at(i).at(j) == '^')
  {
    return 1;
  }

  int cnt = 0;
  field.at(i).at(j) = '1';

  if (i - 1 != pre_i)
  {
    cnt += dfs(field, i - 1, j, i, j);
  }
  if (i + 1 != pre_i)
  {
    cnt += dfs(field, i + 1, j, i, j);
  }
  if (j - 1 != pre_j)
  {
    cnt += dfs(field, i, j - 1, i, j);
  }
  if (j + 1 != pre_j)
  {
    cnt += dfs(field, i, j + 1, i, j);
  }

  if (cnt == 0)
  {
    field.at(i).at(j) = '.';
    return 0;
  }
  else
  {
    field.at(i).at(j) = '^';
    return 1;
  }
}

int main()
{

  ifstream infile("second_second_friend_sample_input.txt");
  ofstream outfile("second_second_friend_sample_output.txt");
  fast_io;
  int T;
  infile >> T;
  for (int test_case = 1; test_case <= T; test_case++)
  {
    outfile << "Case #" << test_case << ": ";

    int r, c;
    infile >> r >> c;
    vector<vector<char>> field(r + 2, vector<char>(c + 2, '#'));

    for (int i = 1; i <= r; i++)
    {
      for (int j = 1; j <= c; j++)
      {
        infile >> field.at(i).at(j);
      }
    }

    bool isPoss = true;
    for (int i = 1; i <= r; i++)
    {
      for (int j = 1; j <= c; j++)
      {
        if (field.at(i).at(j) == '^')
        {
          int cnt = 0;
          cnt += dfs(field, i - 1, j, i, j);
          // cout << i << " " << j << " " << cnt << endl;

          cnt += dfs(field, i + 1, j, i, j);
          // cout << cnt << endl;

          cnt += dfs(field, i, j - 1, i, j);
          // cout << cnt << endl;

          cnt += dfs(field, i, j + 1, i, j);
          // cout << cnt << endl;
          // cout << endl;

          if (cnt < 2)
          {
            isPoss = false;
            // cout << "HERE" << cnt << endl;
          }
        }
      }
    }

    if (isPoss)
    {
      outfile << "Possible" << endl;
      for (int i = 1; i <= r; i++)
      {
        for (int j = 1; j <= c; j++)
        {
          if (field.at(i).at(j) == '1')
          {
            outfile << '.';
          }
          else
          {
            outfile << field.at(i).at(j);
          }
        }
        outfile << endl;
      }
    }
    else
    {
      outfile << "Impossible" << endl;
    }
  }

  return 0;
}