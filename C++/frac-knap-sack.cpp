#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
    long long v;
    long long w;
};

// Custom comparator to sort items by v/w in descending order.
// We use cross-multiplication to avoid floating-point precision issues.
bool compareItems(const Item& a, const Item& b) {
    return a.v * b.w > b.v * a.w;
}

void solve() {
    int n;
    long long W;
    if (!(cin >> n >> W)) return;

    vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].v >> items[i].w;
    }

    // Sort items based on highest joy per unit weight
    sort(items.begin(), items.end(), compareItems);

    double total_joy = 0.0;
    long long current_weight = 0;

    for (int i = 0; i < n; ++i) {
        if (current_weight + items[i].w <= W) {
            // Take the whole item
            current_weight += items[i].w;
            total_joy += items[i].v;
        } else {
            // Take a fraction of the item to fill the bag
            long long remaining_weight = W - current_weight;
            total_joy += items[i].v * ((double)remaining_weight / items[i].w);
            break; // Bag is full
        }
    }

    // Print the result with required precision
    cout << fixed << setprecision(8) << total_joy << "\n";
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
