#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io                 \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define all(x) (x).begin(), (x).end()
int mod = 1000000007;

void dfs_safety(vector<vector<int>> &house, int curr_i, int curr_j, int curr_val)
{
  house.at(curr_i).at(curr_j) = curr_val;
  if (curr_val == 0)
    return;

  if (curr_i - 1 > 0 && house.at(curr_i - 1).at(curr_j) != -2 && house.at(curr_i - 1).at(curr_j) < curr_val)
    dfs_safety(house, curr_i - 1, curr_j, curr_val - 1);

  if (curr_j - 1 > 0 && house.at(curr_i).at(curr_j - 1) != -2 && house.at(curr_i).at(curr_j - 1) < curr_val)
    dfs_safety(house, curr_i, curr_j - 1, curr_val - 1);

  if (curr_i + 1 < house.size() - 1 && house.at(curr_i + 1).at(curr_j) != -2 && house.at(curr_i + 1).at(curr_j) < curr_val)
    dfs_safety(house, curr_i + 1, curr_j, curr_val - 1);

  if (curr_j + 1 < house.at(0).size() - 1 && house.at(curr_i).at(curr_j + 1) != -2 && house.at(curr_i).at(curr_j + 1) < curr_val)
    dfs_safety(house, curr_i, curr_j + 1, curr_val - 1);
}

int dfs_count(vector<vector<int>> &house, int i, int j)
{
  house.at(i).at(j) = -3;
  int cnt = 1;

  if (i - 1 > 0 && house.at(i - 1).at(j) == -1)
    cnt += dfs_count(house, i - 1, j);

  if (j - 1 > 0 && house.at(i).at(j - 1) == -1)
    cnt += dfs_count(house, i, j - 1);

  if (i + 1 < house.size() - 1 && house.at(i + 1).at(j) == -1)
    cnt += dfs_count(house, i + 1, j);

  if (j + 1 < house.at(0).size() - 1 && house.at(i).at(j + 1) == -1)
    cnt += dfs_count(house, i, j + 1);

  return cnt;
}

int main()
{
  fast_io;
  ifstream inputFile("zone_in_input.txt");
  ofstream outputFile("zone_in_output.txt");

  int T;
  inputFile >> T;

  for (int t = 1; t <= T; t++)
  {
    int r, c, s;
    inputFile >> r >> c >> s;

    // s = min(s, max(r, c));

    vector<vector<int>> house(r + 2, vector<int>(c + 2, -2));

    // for (int i = 0; i < c + 2; i++)
    //   house.at(0).at(i) = house.at(r + 1).at(i) = -2;
    // for (int j = 0; j < r + 2; j++)
    //   house.at(j).at(0) = house.at(j).at(c + 1) = -2;

    for (int i = 1; i <= r; i++)
    {
      for (int j = 1; j <= c; j++)
      {
        char ch;
        inputFile >> ch;
        house.at(i).at(j) = ch == '#' ? -2 : -1;
      }
    }

    for (int i = 0; i < r + 2; i++)
    {
      for (int j = 0; j < c + 2; j++)
      {
        if (house.at(i).at(j) == -2)
          dfs_safety(house, i, j, s);
      }
    }

    int max_cnt = 0;
    for (int i = 1; i < r + 1; i++)
    {
      for (int j = 1; j < c + 1; j++)
      {
        if (house.at(i).at(j) == -1)
        {
          max_cnt = max(max_cnt, dfs_count(house, i, j));
        }
      }
    }

    outputFile << "Case #" << t << ": " << max_cnt << endl;

    // cout << max_cnt << endl;
    // for (auto str : house)
    // {
    //   for (auto ch : str)
    //   {
    //     cout << ch;
    //   }
    //   cout << endl;
    // }
    // cout << endl;
  }

  return 0;
}