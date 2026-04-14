#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;
static const int MAXN = 200000 + 5;

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e > 0) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

long long fact[MAXN], invfact[MAXN];

long long C(int n, int r) {
    if (n < 0 || r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD;

    invfact[MAXN - 1] = modpow(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n, k, m;
        cin >> n >> k >> m;

        if (n < k || n > 1LL * k * (m - 1)) {
            cout << 0 << '\n';
            continue;
        }

        if (m == 1) {
            cout << 0 << '\n';
            continue;
        }

        int maxJ = (n - k) / (m - 1);
        long long ans = 0;

        for (int j = 0; j <= maxJ; j++) {
            long long ways = C(k, j) * C(n - 1 - 1LL * j * (m - 1), k - 1) % MOD;
            if (j % 2 == 0) ans = (ans + ways) % MOD;
            else ans = (ans - ways + MOD) % MOD;
        }

        cout << ans % MOD << '\n';
    }

    return 0;
}
