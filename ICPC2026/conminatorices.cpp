```cpp
// ================= COMBINATORICS =================

// ---------- MODULAR POWER ----------
int power(int a, int b, int m = mod) {
    int ans = 1;
    a %= m;

    while (b > 0) {
        if (b & 1)
            ans = (ans * a) % m;

        a = (a * a) % m;
        b >>= 1;Combinatorics
    }

    return ans;
}


// ---------- MODULAR INVERSE ----------
// Works when MOD is prime
int modinv(int a, int m = mod) {
    return power(a, m - 2, m);
}


// =================================================
// FACTORIAL + INVERSE FACTORIAL
// =================================================

const int COMB_MAXN = 1000005;

vector<int> fact(COMB_MAXN);
vector<int> invfact(COMB_MAXN);


// Precompute factorials and inverse factorials
void init_combinatorics() {

    fact[0] = 1;

    for (int i = 1; i < COMB_MAXN; i++)
        fact[i] = fact[i - 1] * i % mod;


    // invfact[n] = 1 / n!
    invfact[COMB_MAXN - 1] =
        modinv(fact[COMB_MAXN - 1]);

    for (int i = COMB_MAXN - 2; i >= 0; i--)
        invfact[i] =
            invfact[i + 1] * (i + 1) % mod;
}


// =================================================
// nCr = n choose r
// =================================================

int nCr(int n, int r) {

    if (r < 0 || r > n)
        return 0;

    return fact[n] *
           invfact[r] % mod *
           invfact[n - r] % mod;
}


// =================================================
// nPr = n permutation r
// =================================================

int nPr(int n, int r) {

    if (r < 0 || r > n)
        return 0;

    return fact[n] *
           invfact[n - r] % mod;
}


// =================================================
// MULTINOMIAL
//
// n! / (a! b! c! ...)
// where a+b+c+... = n
// =================================================

int multinomial(vector<int> v) {

    int n = 0;

    for (int x : v)
        n += x;

    int ans = fact[n];

    for (int x : v)
        ans = ans * invfact[x] % mod;

    return ans;
}


// =================================================
// CATALAN NUMBER
//
// C_n = 1/(n+1) * C(2n,n)
//
// Useful for:
// - Balanced parentheses
// - Number of BSTs
// - Triangulations
// - Non-crossing structures
// =================================================

int catalan(int n) {

    if (2 * n >= COMB_MAXN)
        return -1; // Increase COMB_MAXN

    return nCr(2 * n, n) *
           modinv(n + 1) % mod;
}


// =================================================
// DERANGEMENT
//
// Number of permutations where no element
// remains in its original position.
//
// D[n] = (n-1) * (D[n-1] + D[n-2])
// =================================================

vector<int> derangement(COMB_MAXN);

void init_derangement() {

    derangement[0] = 1;
    derangement[1] = 0;

    for (int i = 2; i < COMB_MAXN; i++) {

        derangement[i] =
            (i - 1) *
            (derangement[i - 1] +
             derangement[i - 2]) % mod;
    }
}


// =================================================
// STARS AND BARS
//
// Number of non-negative solutions:
//
// x1 + x2 + ... + xk = n
//
// Answer = C(n+k-1, k-1)
//
// Example:
// x1+x2+x3 = 5
// => C(7,2)
// =================================================

int stars_bars(int n, int k) {

    if (n < 0 || k <= 0)
        return 0;

    if (n + k - 1 >= COMB_MAXN)
        return -1;

    return nCr(n + k - 1, k - 1);
}


// =================================================
// POSITIVE STARS AND BARS
//
// Number of positive solutions:
//
// x1 + x2 + ... + xk = n
//
// Answer = C(n-1, k-1)
// =================================================

int positive_stars_bars(int n, int k) {

    if (n < k || k <= 0)
        return 0;

    return nCr(n - 1, k - 1);
}


// =================================================
// FALLING FACTORIAL
//
// n * (n-1) * (n-2) * ... * (n-r+1)
//
// = nPr
// =================================================

int falling_factorial(int n, int r) {

    return nPr(n, r);
}


// =================================================
// RISING FACTORIAL
//
// n * (n+1) * (n+2) * ... * (n+r-1)
//
// =================================================

int rising_factorial(int n, int r) {

    if (r < 0)
        return 0;

    int ans = 1;

    for (int i = 0; i < r; i++)
        ans = ans * ((n + i) % mod) % mod;

    return ans;
}


// =================================================
// SUM OF BINOMIAL COEFFICIENTS
//
// C(n,0) + C(n,1) + ... + C(n,n)
// = 2^n
// =================================================

int sum_nCr(int n) {

    return power(2, n);
}


// =================================================
// ALTERNATING SUM OF BINOMIAL COEFFICIENTS
//
// C(n,0) - C(n,1) + C(n,2) - ...
//
// = 0 for n > 0
// =================================================

int alternating_sum_nCr(int n) {

    if (n == 0)
        return 1;

    return 0;
}


// =================================================
// PASCAL TRIANGLE
//
// C[n][r] = C[n-1][r-1] + C[n-1][r]
//
// Useful when:
// - MAXN is small
// - You don't want factorials
// =================================================

vector<vector<int>> pascal(int n) {

    vector<vector<int>> C(
        n + 1,
        vector<int>(n + 1, 0)
    );

    for (int i = 0; i <= n; i++) {

        C[i][0] = 1;
        C[i][i] = 1;

        for (int j = 1; j < i; j++) {

            C[i][j] =
                (C[i - 1][j - 1] +
                 C[i - 1][j]) % mod;
        }
    }

    return C;
}
```