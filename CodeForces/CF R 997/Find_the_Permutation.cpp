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
    vector<string> matrix(n); // Remember its a vector of string...

    for (int i = 0; i < n; i++)
      cin >> matrix.at(i);

    vector<int> permutation;
    permutation.push_back(0);

    for (int i = 1; i < n; i++)
    {
      bool isInserted = false;
      for (int j = permutation.size() - 1; j >= 0; j--)
      {
        if (matrix.at(i).at(permutation.at(j)) == '1')
        {
          permutation.insert(permutation.begin() + j + 1, i);
          isInserted = true;
          break;
        }
      }
      if (!isInserted)
        permutation.insert(permutation.begin(), i);
    }

    for (int p : permutation)
    {
      cout << p + 1 << " ";
    }
    cout << endl;
  }

  return 0;
}