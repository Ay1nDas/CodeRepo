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

    vector<int> nums(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
      cin >> nums.at(i);
      freq[nums.at(i)]++;
    }

    int pairs = 0, not_pairs = 0;
    for (int i = 0; i < n; i++)
    {
      // if (freq[k - nums.at(i)] == -1)
      // {
      //   continue;
      // }
      if (freq[nums.at(i)] == 0)
      {
        continue;
      }
      else
      {
        freq[nums.at(i)]--;
      }

      if (freq[k - nums.at(i)] > 0)
      {
        pairs++;
        freq[k - nums.at(i)]--;
      }
      else
      {
        not_pairs++;
        // cout << nums.at(i) << " ";
      }
    }
    // cout << endl;

    // cout << "P: " << pairs << " " << not_pairs << endl;

    if (not_pairs % 2 == 1)
    {
      cout << 0 << endl;
    }
    else
    {
      cout << pairs << endl;
    }
  }

  return 0;
}