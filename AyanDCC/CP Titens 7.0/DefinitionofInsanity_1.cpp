#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_PRIME = 1000000;
vector<bool> is_prime(MAX_PRIME + 1, true);

// Precompute primes using Sieve of Eratosthenes
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (long long p = 2; p * p <= MAX_PRIME; p++) {
        if (is_prime[p]) {
            for (long long i = p * p; i <= MAX_PRIME; i += p)
                is_prime[i] = false;
        }
    }
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<long long> sweet_numbers;
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;

        // Find the integer square root
        long long root = round(sqrt(num));

        // Check if it's a perfect square and its root is a prime
        if (root * root == num && root <= MAX_PRIME && is_prime[root]) {
            sweet_numbers.push_back(num);
        }
    }

    // Output results
    cout << sweet_numbers.size() << "\n";
    for (int i = 0; i < sweet_numbers.size(); i++) {
        cout << sweet_numbers[i] << (i == sweet_numbers.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    solve();

    return 0;
}
