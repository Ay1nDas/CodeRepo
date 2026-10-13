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

    int midL = -1, midR = -1;
    if (n % 2) {
      midL = midR = n / 2;
    } else {
      midL = n / 2 - 1;
      midR = n / 2;
    }

    int lft = -1, rht = -1;
    if (midL % 2 == position[n]) {
      lft = midL - 1;
      rht = midL + 1;
    } else if(midR % 2 == position[n]) {
      lft = midR - 1;
      rht = midR + 1;
    } else {
      cout << "NO" << endl;
      continue;
    }

    bool isPoss = true;
    for (int i = n - 1; i > 0; i--) {
      if (lft > 0 && position[i] == lft % 2) {
        lft--;
      } else if (rht < n - 1 && position[i] == rht % 2) {
        rht++;
      } else if (lft == 0 && position[i] == lft % 2) {
        lft--;
      } else if (rht == n - 1 && position[i] == rht % 2) {
        rht++;
      } else {
        isPoss = false;
        break;
      }
    }

    if(!isPoss) {
      cout << "NO" << endl;
      continue;
    } else {
      cout << "YES" << endl;
    }
  }

  return 0;
}