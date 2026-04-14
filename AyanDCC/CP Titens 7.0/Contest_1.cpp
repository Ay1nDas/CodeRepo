#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    // Step 1: Build the Adjacency List
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step 2: Bipartite Graph Coloring
    vector<int> color(n + 1, -1);
    vector<pair<int, int>> components;

    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            int size0 = 0, size1 = 0;
            queue<int> q;
            
            q.push(i);
            color[i] = 0;
            size0++;

            bool is_bipartite = true;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        if (color[v] == 0) size0++;
                        else size1++;
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        is_bipartite = false;
                    }
                }
            }

            // If any component has an odd cycle, it's impossible.
            if (!is_bipartite) {
                cout << -1 << "\n";
                return;
            }

            components.push_back({size0, size1});
        }
    }

    // Step 3: Dynamic Programming (Subset Sum)
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (const auto& comp : components) {
        int x = comp.first;
        int y = comp.second;
        vector<bool> next_dp(n + 1, false);
        
        for (int s = 0; s <= n; s++) {
            if (dp[s]) {
                if (s + x <= n) next_dp[s + x] = true;
                if (s + y <= n) next_dp[s + y] = true;
            }
        }
        dp = next_dp;
    }

    // Find the sum that minimizes the absolute difference
    int min_diff = n;
    for (int s = 0; s <= n; s++) {
        if (dp[s]) {
            min_diff = min(min_diff, abs(n - 2 * s));
        }
    }

    cout << min_diff << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
