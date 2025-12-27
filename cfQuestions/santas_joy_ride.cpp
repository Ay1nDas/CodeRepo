#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  int K;
  cin >> N >> K;
  vector<long long> a(N + 1);
  vector<int> b(N + 1);
  for (int i = 1; i <= N; ++i)
    cin >> a[i];
  for (int i = 1; i <= N; ++i)
    cin >> b[i];

  vector<long long> dp(K + 1, 0);

  for (int i = 1; i <= N; ++i)
  {
    int w = b[i];
    long long val = a[i];
    for (int cap = K; cap >= w; --cap)
    {
      dp[cap] = max(dp[cap], dp[cap - w] + val);
    }
  }

  long long ans = 0;
  for (int cap = 0; cap <= K; ++cap)
    ans = max(ans, dp[cap]);
  cout << ans << '\n';
  return 0;
}