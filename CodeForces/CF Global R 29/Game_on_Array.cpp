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
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
      int tmp;
      cin >> tmp;
      freq[tmp]++;
    }

    vector<vector<int>> values;
    for (auto &f : freq)
    {
      values.push_back({f.first, f.second});
    }

    sort(all(values), [](const vector<int> &a, const vector<int> &b)
         { 
          if(a[1] == b[1])
            return a[0] > b[0];
          else
            return a[1] > b[1]; });

    vector<int> maxKeys(values.at(0).at(0));
    for (int i = 1; i < values.size(); i++)
    {
      if (values.at(i - 1).at(0) < values.at(i).at(0))
        maxKeys.push_back(values.at(i).at(0));
    }

    sort(all(values), [](const vector<int> &a, const vector<int> &b)
         { return a[0] > b[0]; });

    vector<ll> points(2);
    int player = 0;

    for (int i = 0; i < maxKeys.size(); i++)
    {
      int key = maxKeys.at(i);

      int l = 0, h = values.size();

      while (l < h)
      {
        int mid = (l + h) / 2;

        if (values.at(mid).at(0) < key)
          h = mid - 1;
        else if (values.at(mid).at(0) > key)
          l = mid + 1;
        else
          l = h = mid;
      }
    }
  }

  return 0;
}