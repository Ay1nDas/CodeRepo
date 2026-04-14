#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;

    vector<int> ones(k, 0);
    vector<int> zeros(k, 0);
    long long totalOnes = 0;

    // Count occurrences of 1s and 0s for each modulo class
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ones[i % k]++;
            totalOnes++;
        } else {
            zeros[i % k]++;
        }
    }

    // Calculate the marginal cost difference of making a position 1 instead of 0
    vector<int> diff(k);
    for (int i = 0; i < k; ++i) {
        diff[i] = zeros[i] - ones[i];
    }

    // Sort to pick the best positions greedily
    sort(diff.begin(), diff.end());

    // Base cost is setting all to 0, then we add the cost of the best m 1s
    long long min_operations = totalOnes;
    for (int i = 0; i < m; ++i) {
        min_operations += diff[i];
    }

    cout << min_operations << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
