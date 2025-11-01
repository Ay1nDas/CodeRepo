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
  int n;
  cin >> n;

  vector<int> coins(n);
  for (auto &i : coins)
  {
    cin >> i;
  }
  sort(all(coins));

  vector<int> possibleSums(1);
  unordered_map<int, int> foundSum;
  for (int i = 0; i < n; i++)
  {
    int currSize = possibleSums.size();
    for (int j = 0; j < currSize; j++)
    {
      int sum = possibleSums.at(j) + coins.at(i);
      if (foundSum[sum] == 0)
      {
        possibleSums.push_back(sum);
        foundSum[sum]++;
      }
    }
  }
  cout << possibleSums.size() - 1 << endl;
  sort(all(possibleSums));
  for (int i = 1; i < possibleSums.size(); i++)
  {
    cout << possibleSums.at(i) << " ";
  }
  cout << endl;
  return 0;
}