#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // dp[i][0] = max length ending at i with 0 violations
    // dp[i][1] = max length ending at i with 1 violation
    vector<vector<int>> dp(n, vector<int>(2, 1));
    int max_len = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (abs(a[i] - a[j]) <= k) {
                // No violation introduced
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
                dp[i][1] = max(dp[i][1], dp[j][1] + 1);
            } else {
                // Violation introduced
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
        }
        max_len = max({max_len, dp[i][0], dp[i][1]});
    }

    cout << max_len << "\n";
    
    return 0;
}
