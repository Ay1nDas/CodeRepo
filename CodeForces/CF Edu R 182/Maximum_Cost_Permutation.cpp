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
    int missing = 0;
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
      cin >> arr.at(i);
      freq[arr.at(i)]++;
      if (arr.at(i) == 0)
        missing++;
    }

    int missingElem = -1;
    for (int i = 1; i <= n; i++)
    {
      if (freq[i] == 0)
        missingElem = i;
    }

    int front;
    for (front = 0; front < n; front++)
    {
      if (arr.at(front) == 0 && missing == 1 && missingElem == front + 1)
        continue;
      else if (arr.at(front) != front + 1)
        break;
    }

    int back;
    for (back = n - 1; back >= 0; back--)
    {
      if (arr.at(back) == 0 && missing == 1 && missingElem == back + 1)
        continue;
      else if (arr.at(back) != back + 1)
        break;
    }

    // cout << "ans: ";

    if (back > front)
      cout << back - front + 1 << endl;
    else
      cout << 0 << endl;
  }

  return 0;
}