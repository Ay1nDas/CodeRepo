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

    vector<int> pres_mats(n), reqd_mats(n);
    int total_mats_present = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> pres_mats.at(i);
      total_mats_present += pres_mats.at(i);
    }

    int total_mats_reqd = 0;
    int operations = 0;
    int opp_index = 0;

    for (int i = 0; i < n; i++)
    {
      cin >> reqd_mats.at(i);
      total_mats_reqd += reqd_mats.at(i);
      if (pres_mats.at(i) < reqd_mats.at(i))
      {
        operations++;
        opp_index = i;
      }
    }

    // if (n == 1)
    // {
    //   cout << (reqd_mats.at(0) <= pres_mats.at(0) ? "YES" : "NO") << endl;
    //   continue;
    // }

    if (operations > 1)
    {
      cout << "NO" << endl;
      continue;
    }

    int material_cost = reqd_mats.at(opp_index) - pres_mats.at(opp_index);
    bool isPossible = true;

    for (int i = 0; i < n; i++)
    {
      if (i == opp_index)
      {
        continue;
      }
      else if (pres_mats.at(i) - material_cost < reqd_mats.at(i))
      {
        isPossible = false;
        break;
      }
    }
    cout << (isPossible ? "YES" : "NO") << endl;

    // bool isPossible = true;
    // int convert = 0;

    // for (int i = 0; i < n; i++)
    // {
    //   if (pres_mats.at(i) - convert < reqd_mats.at(i))
    //   {
    //     if (convert > 0)
    //     {
    //       isPossible = false;
    //       break;
    //     }

    //     total_mats_present -= (reqd_mats.at(i) - pres_mats.at(i)) * (n - 2);
    //     convert += reqd_mats.at(i) - pres_mats.at(i);
    //     if (total_mats_present < total_mats_reqd)
    //     {
    //       isPossible = false;
    //       break;
    //     }
    //   }
    // }
    // cout << (isPossible ? "YES" : "NO") << endl;
  }

  return 0;
}