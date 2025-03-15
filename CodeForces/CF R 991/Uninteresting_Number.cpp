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
    string number;
    cin >> number;

    int num_sum{0}, two_count{0}, three_count{0};

    for (int i = 0; i < number.length(); i++)
    {
      int n = number.at(i) - '0';

      num_sum += n;
      if (n == 2)
        two_count++;
      else if (n == 3)
        three_count++;
    }

    ll remainder = num_sum % 9;

    // cout << remainder << endl
    //      << endl;

    // if (remainder == 0)
    // {
    //   cout << "YES" << endl;
    //   continue;
    // }

    bool can_divide = false;
    while (three_count--)
    {
      if (remainder % 9 == 0)
      {
        // cout << "HERE0" << endl;
        can_divide = true;
        break;
      }
      if (two_count > 0 && (remainder + 2) % 9 == 0)
      {
        // cout << "HERE1" << endl;
        can_divide = true;
        break;
      }
      if (two_count > 1 && (remainder + 4) % 9 == 0)
      {
        // cout << "HERE2" << endl;
        can_divide = true;
        break;
      }

      remainder += 6;
    }

    if (remainder % 9 == 0)
      can_divide = true;

    while (two_count--)
    {
      if (remainder % 9 == 0)
      {
        // cout << "HERE3" << endl;
        can_divide = true;
        break;
      }
      remainder += 2;
    }

    if (remainder % 9 == 0)
      can_divide = true;

    cout << (can_divide ? "YES" : "NO") << endl;
  }

  return 0;
}