#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate
#include <algorithm> // For std::max_element

using namespace std;

// Function to check if it is possible to divide the array into at most K groups
// such that the maximum sum of any group is <= max_difficulty.
bool isValid(long long max_difficulty, int n, int k, const vector<long long>& a) {
    int groups = 1; // Start with the first group
    long long current_sum = 0;

    for (int i = 0; i < n; ++i) {
        // If a single event is harder than the max_difficulty, it's impossible
        if (a[i] > max_difficulty) return false;

        if (current_sum + a[i] <= max_difficulty) {
            // Add event to current group
            current_sum += a[i];
        } else {
            // Start a new group
            groups++;
            current_sum = a[i];
        }
    }
    
    // If we used K or fewer groups, this max_difficulty is feasible
    return groups <= k;
}

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    vector<long long> a(n);
    long long max_val = 0;
    long long total_sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_val = max(max_val, a[i]);
        total_sum += a[i];
    }

    // Binary Search for the minimum possible Maximum Group Difficulty
    long long low = max_val;
    long long high = total_sum;
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (isValid(mid, n, k, a)) {
            ans = mid;      // mid is a possible answer, try to minimize it
            high = mid - 1;
        } else {
            low = mid + 1;  // mid is too small, need larger capacity
        }
    }

    cout << ans << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}