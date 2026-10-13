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
    int m, n;
    cin >> n >> m;
    
    vector<int> arr(n);
    for (auto &i : arr) {
      cin >> i;
    }

    priority_queue<int> max_heap;

    vector<ll> sum(n);
    ll curr_sum = 0;

    // cout << "Sum i: ";
    for(int i = 0; i < n; i++) {
      curr_sum += arr[i];
      max_heap.push(arr[i]);

      if (max_heap.size() > m - 1) {
        curr_sum -= max_heap.top();
        max_heap.pop();
      }

      sum[i] = curr_sum;
      // cout << sum[i] << " ";
    }
    // cout << endl;

    ll max_pill = LONG_LONG_MIN;
    for (int i = n - 1; i >= m - 1; i--) {
      max_pill = max(max_pill, m * static_cast<long long>(arr[i]) - (i - 1 >= 0 ? sum[i - 1] : 0));
    }

    // cout << "Ans: ";
    cout << max_pill << endl;

  }

  return 0;
}