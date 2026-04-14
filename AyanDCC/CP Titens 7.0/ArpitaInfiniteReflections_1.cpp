#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;
const int MAX = 200005;

long long fact[MAX];
long long invFact[MAX];

// Fast exponentiation
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// Precompute factorials and inverse factorials for O(1) nCr
void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX - 1] = power(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

void solve() {
    long long n, k, m;
    cin >> n >> k >> m;

    // Impossible distributions
    if (n < k || m <= 1) {
        cout << 0 << "\n";
        return;
    }

    long long S = n - k;
    long long m_minus_1 = m - 1;
    long long ans = 0;

    // Evaluate the summation formula
    for (long long j = 0; j * m_minus_1 <= S && j <= k; j++) {
        long long term = (nCr(k, j) * nCr(S - j * m_minus_1 + k - 1, k - 1)) % MOD;
        if (j % 2 == 1) {
            ans = (ans - term + MOD) % MOD; // Subtraction under modulo
        } else {
            ans = (ans + term) % MOD;       // Addition under modulo
        }
    }

    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
