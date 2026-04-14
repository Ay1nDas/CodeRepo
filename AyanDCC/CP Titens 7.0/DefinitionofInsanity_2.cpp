#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    const int LIM = 316227; // floor(sqrt(1e11)) + 1
    vector<bool> isPrime(LIM + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; 1LL * i * i <= LIM; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= LIM; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<long long> ans;
    for (long long x : a) {
        long long r = sqrtl((long double)x);
        while ((r + 1) * (r + 1) <= x) r++;
        while (r * r > x) r--;

        if (r * r == x && r <= LIM && isPrime[(int)r]) {
            ans.push_back(x);
        }
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < (int)ans.size(); i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}
