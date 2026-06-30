#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

// Pass total_guilds by reference to avoid heavy struct returns
int get_guilds(const vector<vector<int>> &tree, int head, ll &total_guilds) {
    int max_sz = -1;
    int sec_max_sz = -1;

    // Use standard [] instead of .at() to remove bounds-checking overhead
    for (int node : tree[head]) {
        int h = get_guilds(tree, node, total_guilds);
        
        if (h > max_sz) {
            sec_max_sz = max_sz;
            max_sz = h;
        } else if (h > sec_max_sz) {
            sec_max_sz = h;
        }
    }

    // Every node adds 1 for its own h=0 guild
    total_guilds += 1;

    // Add overlapping guilds from having multiple branches
    if (sec_max_sz != -1) {
        total_guilds += (sec_max_sz + 1);
    }

    return max_sz + 1;
}

int main() {
    fast_io;
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> tree(n + 1);

        for(int i = 2; i <= n; i++) {
            int head;
            cin >> head;
            tree[head].push_back(i);
        }

        ll total_guild = 0;
        get_guilds(tree, 1, total_guild);
        
        // Use "\n" instead of endl!
        cout << total_guild << "\n";
    }

    return 0;
}
