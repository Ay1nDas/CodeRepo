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
    int n, k;
    cin >> n >> k;

    string choice;
    cin >> choice;

    if (n == k)
    {
      for (int i = 0; i < n; i++)
        cout << '-';
      cout << endl;
      continue;
    }

    vector<char> state(n, '+');
    vector<int> cnts(3);
    for (auto c : choice)
      cnts.at(c - '0')++;

    // for (int i = 0; i < k; i++)
    // {
    //   switch (choice.at(i))
    //   {
    //   case '0':
    //     state.at(l) = state.at(l - 1);
    //     state.at(l - 1) = '-';
    //     l++;
    //     break;
    //   case '1':
    //     state.at(r) = state.at(r + 1);
    //     state.at(r + 1) = '-';
    //     r--;
    //     break;
    //   case '2':
    //     state.at(l) = state.at(r) = '?';
    //     l++;
    //     r--;
    //     break;
    //   }
    // }

    int l = 0, r = n - 1;
    for (l = 0; l < cnts.at(0); l++)
      state.at(l) = '-';
    for (r = n - 1; n - 1 - r < cnts.at(1); r--)
      state.at(r) = '-';
    for (int i = 0; i < cnts.at(2); i++)
      state.at(l++) = state.at(r--) = '?';

    for (int i = 0; i < n; i++)
      cout << state.at(i);
    cout << endl;
  }

  return 0;
}