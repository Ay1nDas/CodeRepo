#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> dp0(n, 1), dp1(n, 1);
    int ans = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (llabs(a[i] - a[j]) <= k) {
                dp0[i] = max(dp0[i], dp0[j] + 1);
                dp1[i] = max(dp1[i], dp1[j] + 1);
                dp1[i] = max(dp1[i], dp0[j] + 1);
            } else {
                dp1[i] = max(dp1[i], dp0[j] + 1);
            }
        }
        ans = max(ans, max(dp0[i], dp1[i]));
    }

    cout << ans << '\n';
    return 0;
}
