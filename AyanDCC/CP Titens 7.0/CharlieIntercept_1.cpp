#include <iostream>

using namespace std;

// Extended Euclidean Algorithm to find the modular inverse
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// Function to calculate (a^-1) mod m
long long modInverse(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return (x % m + m) % m; // Ensure the result is positive
}

void solve() {
    long long n, m, k, c;
    cin >> n >> m >> k >> c;

    // Calculate the modular inverse of K modulo M only once per test case
    long long k_inv = modInverse(k, m);

    for (int i = 0; i < n; ++i) {
        long long y;
        cin >> y;
        
        // Handle potential negative values safely
        long long val = (y - c) % m;
        if (val < 0) val += m;
        
        long long x = (val * k_inv) % m;
        
        cout << x << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
