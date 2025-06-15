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
    unordered_map<int, int> freq_of_colour;
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
      int colour;
      cin >> colour;
      freq_of_colour[colour]++;
    }

    for (int i = 1; i <= n; i++)
      freq[freq_of_colour[i]]++;

    int alice_points{0};
    alice_points += ((freq[1] + 1) / 2) * 2;

    for (int i = 2; i <= n; i++)
      alice_points += freq[i];

    cout << alice_points << endl;
  }

  return 0;
}