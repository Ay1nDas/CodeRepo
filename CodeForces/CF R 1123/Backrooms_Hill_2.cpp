#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
    vector <int> arr(n);
    for (auto &i : arr) {
      cin >> i;
    }

    vector<int> position(n + 1);
    position[0] = -1;
    for (int i = 0; i < arr.size(); i++) {
      position[arr[i]] = (i % 2);
    }

    int lft = 0, rht = n - 1;
    bool isPoss = true;
  
    for (int i = 1; i <= n; i++) {
      if (position[i] == lft % 2) {
        lft++;
      } else if (position[i] == rht % 2) {
        rht--;
      } else {
        isPoss = false;
        break;
      }
    }

    cout << (isPoss ? "YES" : "NO") << endl; 
  }

  return 0;
}