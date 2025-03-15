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
    vector<int> arr(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
      cin >> arr.at(i);
      freq[arr.at(i)]++;
      // freq[arr[i]]++;
    }

    int max_val = 0, current_val = 0;
    int max_index_start = -1, max_index_end = -1;
    int index_start = -1, index_end = -1;

    for (int i = 0; i < n; i++)
    {
      // cout << freq[arr.at(i)] << " ";
      if (freq[arr.at(i)] == 1 && index_start == -1)
      {
        index_start = i;
        index_end = i;
      }
      else if (freq[arr.at(i)] == 1)
      {
        index_end = i;
      }
      else
      {
        current_val = index_end - index_start + 1;

        if (current_val > max_val && index_start >= 0)
        {
          max_index_start = index_start;
          max_index_end = index_end;
          max_val = current_val;
          // cout << "Here: " << index_start << " " << index_end << endl;
        }

        index_start = -1;
        index_end = -1;
      }
    }
    // cout << endl;

    // cout << "Here: " << index_start << " " << index_end << endl;

    current_val = index_end - index_start + 1;

    if (current_val > max_val && index_start >= 0)
    {
      max_index_start = index_start;
      max_index_end = index_end;
      max_val - current_val;
    }

    if (max_index_start == -1)
    {
      cout << 0 << endl;
    }
    else
    {
      cout << max_index_start + 1 << " " << max_index_end + 1 << endl;
    }
  }

  return 0;
}