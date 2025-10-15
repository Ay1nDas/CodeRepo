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

int main()
{

  fast_io;
  int T;
  ifstream inputFile("warm_up_input.txt");
  ofstream outputFile("warm_up_output.txt");
  inputFile >> T;
  for (int t = 1; t <= T; t++)
  {
    int n;
    inputFile >> n;

    vector<vector<int>> temps(n + 1, vector<int>(2));
    for (int i = 1; i <= n; i++)
      inputFile >> temps.at(i).at(0);
    for (int i = 1; i <= n; i++)
      inputFile >> temps.at(i).at(1);

    bool isPossible = true;
    for (int i = 1; i <= n; i++)
    {
      if (temps.at(i).at(0) > temps.at(i).at(1))
      {
        isPossible = false;
        break;
      }
    }

    if (!isPossible)
    {
      outputFile << "Case #" << t << ": " << -1 << endl;
      continue;
    }

    unordered_map<int, queue<int>> tempQueue;
    for (int i = 1; i <= n; i++)
      tempQueue[temps.at(i).at(0)].push(i);

    vector<vector<int>> sorted_final_temps(n + 1, vector<int>(2));
    for (int i = 1; i <= n; i++)
    {
      sorted_final_temps.at(i).at(0) = i;
      sorted_final_temps.at(i).at(1) = temps.at(i).at(1);
    }
    sort(sorted_final_temps.begin() + 1, sorted_final_temps.end(), [](const vector<int> &a, const vector<int> &b)
         { return (a[1] == b[1]) ? a[0] < b[0] : a[1] < b[1]; });

    vector<vector<int>> ops;
    for (auto &dish : sorted_final_temps)
    {
      int idx = dish.at(0);
      int req_temp = dish.at(1);
      if (temps.at(idx).at(0) < temps.at(idx).at(1))
      {
        if (tempQueue[temps.at(idx).at(1)].size() != 0)
        {
          tempQueue[temps.at(idx).at(0)].pop();
          tempQueue[temps.at(idx).at(1)].push(idx);

          ops.push_back({idx, tempQueue[temps.at(idx).at(1)].front()});
        }
        else
        {
          isPossible = false;
          break;
        }
      }
    }

    if (!isPossible)
    {
      outputFile << "Case #" << t << ": " << -1 << endl;
    }
    else
    {
      outputFile << "Case #" << t << ": " << ops.size() << endl;
      for (auto &o : ops)
      {
        outputFile << o.at(0) << " " << o.at(1) << endl;
      }
    }
  }
  inputFile.close();
  outputFile.close();

  return 0;
}
