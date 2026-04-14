#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, a;
        cin >> n >> a;

        long long x = 1LL * a * n;

        int s1 = x / 180;
        int s2 = s1 + 1;

        s1 = max(1, min(n - 2, s1));
        s2 = max(1, min(n - 2, s2));

        auto diff = [&](int s) {
            return llabs(180LL * s - x);
        };

        int s = diff(s1) <= diff(s2) ? s1 : s2;

        cout << 2 << ' ' << 1 << ' ' << s + 2 << '\n';
    }

    return 0;
}
