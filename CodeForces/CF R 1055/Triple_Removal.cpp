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
    int n, q;
    vector<int> arr(n + 1);
    for (int i = 1; i < n + 1; i++)
      cin >> arr.at(i);

    while (q--)
    {
      int start, end;
      cin >> start >> end;

      stack<int> st;
      vector<int> pairs(2);
      int points = 0;

      for (int i = start; i <= end; i++)
      {
        if (st.size() == 0)
        {
          st.push(arr.at(i));
        }
        else if (st.top() == arr.at(i))
        {
          st.pop();
          pairs.at(arr.at(i))++;
        }
        // else if (pairs.at(st.top()) > 0)
        // {
        //   pairs.at(st.top())--;
        //   st.pop();
        //   points++;
        //   st.push(arr.at(i));
        // }
        else
        {
          st.push(arr.at(i));
        }
      }

      if (st.top() > 0)
      {
        int oneLeft = 0, zeroLeft = 0;
        if (st.top() == 1)
        {
          oneLeft = st.size() / 2 + (st.size() % 2 ? 1 : 0);
          zeroLeft = st.size() / 2;
        }
        else
        {
          zeroLeft = st.size() / 2 + (st.size() % 2 ? 1 : 0);
          oneLeft = st.size() / 2;
        }

        if (pairs.at((st.top() + 1) % 2) > 0)
        {
          points++;
          pairs.at((st.top() + 1) % 2)--;
        }
        else
        {
          points += 2;
          if (st.top() == 0)
            zeroLeft -= 3;
          else
            oneLeft -= 3;
        }

        points += zeroLeft / 3;
        zeroLeft %= 3;

        points += oneLeft / 3;
        oneLeft %= 3;

        if (zeroLeft >= pairs.at(0))
        {
          points += zeroLeft;
          pairs.at(0) -= zeroLeft;
        }
        else
        {
          cout << -1 << endl;
          continue;
        }

        if (oneLeft >= pairs.at(1))
        {
          points += oneLeft;
          pairs.at(1) -= oneLeft;
        }
        else
        {
          cout << -1 << endl;
          continue;
        }
      }
      points += pairs.at(0) / 3 + pairs.at(1) / 3;
      pairs.at(0) %= 3;
      pairs.at(1) %= 3;
    }
  }

  return 0;
}