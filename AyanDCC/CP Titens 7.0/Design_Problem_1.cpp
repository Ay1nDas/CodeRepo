#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    long long n, a;
    cin >> n >> a;
    
    long long target = a * n;
    
    // Calculate the two closest integer values for k
    long long k1 = target / 180;
    long long k2 = k1 + 1;
    
    // Clamp k1 and k2 to the valid range [1, n-2]
    k1 = max(1LL, min(k1, n - 2));
    k2 = max(1LL, min(k2, n - 2));
    
    // Calculate absolute differences avoiding floating point math
    long long diff1 = abs(k1 * 180 - target);
    long long diff2 = abs(k2 * 180 - target);
    
    long long best_k = k1;
    if (diff2 < diff1) {
        best_k = k2;
    }
    
    // Output v1, v2, v3
    cout << 2 << " " << 1 << " " << best_k + 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
