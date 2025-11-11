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
    int n, m;
    cin >> n >> m;
    multiset<int> swords;
    vector<pair<int, int>> monsters(m);

    for (int i = 0; i < n; i++)
    {
      int num;
      cin >> num;
      swords.insert(num);
    }
    for (int i = 0; i < m; i++)
    {
      cin >> monsters.at(i).first;
    }
    for (int i = 0; i < m; i++)
    {
      cin >> monsters.at(i).second;
    }

    sort(monsters.begin(), monsters.end());

    vector<pair<int, int>> monstersNoZero;
    vector<int> monstersZero;
    for (auto &p : monsters)
    {
      if (p.second == 0)
      {
        monstersZero.push_back(p.first);
      }
      else
      {
        monstersNoZero.push_back(p);
      }
    }

    int cnt = 0;
    for (int i = 0; i < monstersNoZero.size(); i++)
    {
      auto it = swords.lower_bound(monstersNoZero.at(i).first);
      if (it == swords.end())
      {
        break;
      }
      else
      {
        cnt++;
      }

      int sword = *it;
      if (sword != max(sword, monstersNoZero.at(i).second))
      {
        swords.erase(it);
        swords.insert(monstersNoZero.at(i).second);
      }
    }

    for (int i = 0; i < monstersZero.size(); i++)
    {
      auto it = swords.lower_bound(monstersZero.at(i));
      if (it == swords.end())
      {
        break;
      }
      else
      {
        swords.erase(it);
        cnt++;

        // for (auto i : swords)
        // {
        //   cout << i << " ";
        // }
        // cout << endl;
      }
    }

    cout << cnt << endl;
  }

  return 0;
}