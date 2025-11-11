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

    vector<int> perm(n + 1);
    for (int i = 1; i <= n; i++)
    {
      cin >> perm.at(i);
    }

    string x;
    cin >> x;
    x = ' ' + x;
    string s(x.length(), '0');
    vector<pair<int, int>> ops;
    bool isPoss = true;

    for (int i = 1; i <= n; i++)
    {
      if (x.at(i) == '1' && s.at(i) == '0')
      {
        if (ops.size() == 5)
        {
          isPoss = false;
          break;
        }

        int l1 = -1, r1 = -1;
        int min_p1 = perm.at(i);
        for (int j = 1; j < i; j++)
        {
          if (perm.at(j) < perm.at(i))
          {
            if (l1 == -1 || perm.at(j) < min_p1)
            {
              min_p1 = perm.at(j);
              l1 = j;
            }
          }
        }
        int max_p1 = perm.at(i);
        for (int j = i + 1; j <= n; j++)
        {
          if (perm.at(j) > perm.at(i))
          {
            if (r1 == -1 || perm.at(j) > max_p1)
            {
              max_p1 = perm.at(j);
              r1 = j;
            }
          }
        }

        int l2 = -1, r2 = -1;
        int max_p2 = perm.at(i);
        for (int j = 1; j < i; j++)
        {
          if (perm.at(j) > perm.at(i))
          {
            if (l2 == -1 || perm.at(j) > max_p2)
            {
              max_p2 = perm.at(j);
              l2 = j;
            }
          }
        }
        int min_p2 = perm.at(i);
        for (int j = i + 1; j <= n; j++)
        {
          if (perm.at(j) < perm.at(i))
          {
            if (r2 == -1 || perm.at(j) < min_p2)
            {
              min_p2 = perm.at(j);
              r2 = j;
            }
          }
        }

        bool case1_exists = (l1 != -1 && r1 != -1);
        bool case2_exists = (l2 != -1 && r2 != -1);

        if (!case1_exists && !case2_exists)
        {
          isPoss = false;
          break;
        }

        int l = -1, r = -1;
        int score1 = 0, score2 = 0;

        if (case1_exists)
        {
          int minP = min(perm.at(l1), perm.at(r1));
          int maxP = max(perm.at(l1), perm.at(r1));
          for (int j = l1 + 1; j < r1; j++)
          {
            if (x.at(j) == '1' && s.at(j) == '0' && perm.at(j) > minP && perm.at(j) < maxP)
            {
              score1++;
            }
          }
        }
        if (case2_exists)
        {
          int minP = min(perm.at(l2), perm.at(r2));
          int maxP = max(perm.at(l2), perm.at(r2));
          for (int j = l2 + 1; j < r2; j++)
          {
            if (x.at(j) == '1' && s.at(j) == '0' && perm.at(j) > minP && perm.at(j) < maxP)
            {
              score2++;
            }
          }
        }

        if (score1 >= score2)
        {
          l = l1;
          r = r1;
        }
        else
        {
          l = l2;
          r = r2;
        }

        ops.push_back({l, r});
        int minP = min(perm.at(l), perm.at(r));
        int maxP = max(perm.at(l), perm.at(r));
        for (int j = l + 1; j < r; j++)
        {
          if (perm.at(j) > minP && perm.at(j) < maxP)
          {
            s.at(j) = '1';
          }
        }
      }
    }

    for (int i = 1; i <= n; i++)
    {
      if (x.at(i) == '1' && s.at(i) == '0')
      {
        isPoss = false;
        break;
      }
    }

    // cout << endl
    //  << "ANS: " << endl;

    if (isPoss == false)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << ops.size() << endl;
      for (auto &p : ops)
      {
        cout << p.first << " " << p.second << endl;
      }
    }
  }

  return 0;
}