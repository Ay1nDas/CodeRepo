#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k, m;
        cin >> n >> k >> m;

        string s;
        cin >> s;

        vector<int> ones(k, 0), sz(k, 0);

        for (int i = 0; i < n; i++) {
            int r = i % k;
            sz[r]++;
            if (s[i] == '1') ones[r]++;
        }

        long long ans = 0;
        vector<long long> extra;
        extra.reserve(k);

        for (int r = 0; r < k; r++) {
            ans += ones[r]; // cost if this group becomes all 0
            extra.push_back(1LL * sz[r] - 2LL * ones[r]);
        }

        sort(extra.begin(), extra.end());

        for (int i = 0; i < m; i++) {
            ans += extra[i];
        }

        cout << ans << '\n';
    }

    return 0;
}
