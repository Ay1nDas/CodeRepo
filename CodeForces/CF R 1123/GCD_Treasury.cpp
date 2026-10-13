#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) (x).begin(), (x).end()
int mod = 1000000007;

vector<int> getPrimeFactors(int num) {
  vector<int> primeFactors;
  for (int p = 2; p * p <= num; p++) {
      if (num % p == 0) {
        primeFactors.push_back(p);
        num /= p;
      }
      while (num % p == 0) {
        num /= p;
      }
    }

    if (num > 1) {
      primeFactors.push_back(num);
    }

    return primeFactors;
}

int main()
{

  fast_io;
  int T;
  cin >> T;
  while (T--)
  {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (auto &i : arr) {
      cin >> i;
    }
    
    vector<int> primeFactorX = getPrimeFactors(x);
    // for (auto &i : primeFactorX) {
    //   cout << i << " ";
    // }
    // cout << endl;

    vector<ll> primeSum(primeFactorX.size());

    for (auto &i : arr) {
      for (int j = 0; j < primeFactorX.size(); j++) {
        if (i % primeFactorX[j] == 0) {
          primeSum[j] += i;
        }
      }
    }

    ll max_sum = 0;
    for (auto &i : primeSum) {
      max_sum = max(i, max_sum);
    }

    // cout << "Ans: ";
    cout << max_sum << endl;
  }

  return 0;
}