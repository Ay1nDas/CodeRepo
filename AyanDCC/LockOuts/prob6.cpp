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
  int n, k;
  cin >> n >> k;
  vector<int> elements(n);
  unordered_map<int, int> freq;
  bool isPossible = true;
  int max_freq = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> elements.at(i);
    freq[elements.at(i)]++;
    if (freq[elements.at(i)] > k)
    {
      isPossible = false;
    }

    if (freq[elements.at(i)] > max_freq)
    {
      max_freq = freq[elements.at(i)];
    }
  }

  if (isPossible)
  {
    cout << "YES" << endl;
    int print_k = 0;
    bool onePrinted = false;

    for (int i = 0; i < n; i++)
    {
      if (freq[elements.at(i)] == 1 && onePrinted && max_freq < k)
      {
        max_freq++;
        cout << max_freq << " ";
      }
      else if (freq[elements.at(i)] == 1)
      {
        cout << 1 << " ";
        onePrinted = true;
      }
      else
      {
        cout << freq[elements.at(i)] << " ";
      }

      freq[elements.at(i)]--;
    }
    cout << endl;
  }
  else
  {
    cout << "NO" << endl;
  }

  return 0;
}