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
  ifstream inputFile("plan_out_validation_input.txt");
  ofstream outputFile("plan_out_validation_output.txt");

  fast_io;
  int T;
  inputFile >> T;
  for (int t = 1; t <= T; t++)
  {
    int n, m;
    inputFile >> n >> m;

    vector<pair<int, int>> pairs(m + 1);
    for (int i = 1; i < m + 1; i++)
    {
      inputFile >> pairs.at(i).first;
      inputFile >> pairs.at(i).second;
    }

    vector<pair<ll, ll>> dpValues(m + 1);
    vector<pair<int, int>> dpDays(m + 1);

    pair<unordered_map<int, ll>, unordered_map<int, ll>> coderCount1;
    // pair<unordered_map<int, ll>, unordered_map<int, ll>> coderCount2;

    for (int i = 1; i < m + 1; i++)
    {
      // take day 1
      ll valuePre1 = 0;
      valuePre1 += 2 * (coderCount1.first[pairs.at(i).first] + coderCount1.first[pairs.at(i).second] + 1);

      ll valuePre2 = 2 * (coderCount1.second[pairs.at(i).first] + coderCount1.second[pairs.at(i).second] + 1);

      // take day 2
    }
  }

  return 0;
}