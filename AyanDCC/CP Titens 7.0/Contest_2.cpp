#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> g(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> color(N + 1, -1);
    vector<pair<int,int>> comps;

    for (int i = 1; i <= N; i++) {
        if (color[i] != -1) continue;

        queue<int> q;
        q.push(i);
        color[i] = 0;
        int cnt[2] = {1, 0};
        bool ok = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : g[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    cnt[color[v]]++;
                    q.push(v);
                } else if (color[v] == color[u]) {
                    ok = false;
                }
            }
        }

        if (!ok) {
            cout << -1 << '\n';
            return 0;
        }

        comps.push_back({cnt[0], cnt[1]});
    }

    vector<char> dp(N + 1, false), ndp(N + 1, false);
    dp[0] = true;

    for (auto [a, b] : comps) {
        fill(ndp.begin(), ndp.end(), false);
        for (int s = 0; s <= N; s++) {
            if (!dp[s]) continue;
            if (s + a <= N) ndp[s + a] = true;
            if (s + b <= N) ndp[s + b] = true;
        }
        dp.swap(ndp);
    }

    int ans = N;
    for (int s = 0; s <= N; s++) {
        if (dp[s]) ans = min(ans, abs(N - 2 * s));
    }

    cout << ans << '\n';
    return 0;
}
