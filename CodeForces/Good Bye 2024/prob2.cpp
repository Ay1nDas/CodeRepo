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

    vector<int> arr_start(n);
    vector<int> arr_end(n);

    unordered_map<int, int> ratings;
    unordered_map<int, int> rev_ratings;

    for (int i = 0; i < n; i++)
    {
      cin >> arr_start.at(i) >> arr_end.at(i);

      if (arr_start.at(i) == arr_end.at(i))
        ratings[arr_start.at(i)]++;
    }

    int rev_val = 0;
    for (int i = 0; i < 2 * n + 1; i++)
    {
      if (ratings[i] == 0)
        rev_val++;
      rev_ratings[i] = rev_val;
    }

    for (int i = 0; i < n; i++)
    {
      if (arr_start.at(i) == arr_end.at(i))
      {
        if (ratings[arr_start.at(i)] > 1)
          cout << "0";
        else
          cout << "1";
      }
      else
      {
        // bool isZero = true;
        // for (int j = arr_start.at(i); j <= arr_end.at(i); j++)
        // {
        //   if (ratings[j] == 0)
        //   {
        //     isZero = false;
        //     break;
        //   }
        // }

        // cout << (isZero ? "0" : "1");

        if (rev_ratings[arr_end.at(i)] - rev_ratings[arr_start.at(i) - 1] == 0)
          cout << "0";
        else
          cout << "1";
      }
    }
    cout << endl;
  }

  return 0;
}