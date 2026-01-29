#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long low = 0, high = 0;

    // Define search space
    for (long long x : A) {
        low = max(low, x);  // at least the max element
        high += x;          // at most sum of all elements
    }

    long long ans = high;

    while (low <= high) {
        long long mid = (low + high) / 2;

        // Check if we can split into <= K groups
        long long currentSum = 0;
        int groups = 1;

        for (int i = 0; i < N; i++) {
            if (currentSum + A[i] <= mid) {
                currentSum += A[i];
            } else {
                groups++;
                currentSum = A[i];
            }
        }

        if (groups <= K) {
            ans = mid;
            high = mid - 1;  // try to minimize
        } else {
            low = mid + 1;   // need larger max difficulty
        }
    }

    cout << ans << "\n";
    return 0;
}
