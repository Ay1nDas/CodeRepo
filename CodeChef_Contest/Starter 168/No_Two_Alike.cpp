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
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    unordered_map<int, int> intMap;
    unordered_set<int> unique, multiple;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
      cin >> arr.at(i);
      intMap[arr.at(i)]++;
    }

    int cost = 0;
    for (int i = 0; i < n; i++)
    {
      if (intMap[arr.at(i)] > 1)
      {
        multiple.insert(arr.at(i));
        intMap[arr.at(i)]--;
      }
      else if (multiple.size() > 0 && intMap[arr.at(i)] == 1)
      {
        unique.insert(arr.at(i));
        multiple.erase(arr.at(i));
      }

      if (multiple.empty())
      {
        cost += unique.size();
        unique.clear();
      }
    }
    cout << cost << endl;
  }

  return 0;
}