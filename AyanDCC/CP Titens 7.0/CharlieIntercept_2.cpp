#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int64 ext_gcd(int64 a, int64 b, int64 &x, int64 &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int64 x1, y1;
    int64 g = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

int64 mod_inv(int64 a, int64 mod) {
    int64 x, y;
    ext_gcd(a, mod, x, y);
    x %= mod;
    if (x < 0) x += mod;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        int64 M, K, C;
        cin >> N >> M >> K >> C;

        int64 invK = mod_inv(K, M);

        for (int i = 0; i < N; i++) {
            int64 y;
            cin >> y;
            int64 x = (y - C) % M;
            if (x < 0) x += M;
            x = (x * invK) % M;

            cout << x << (i + 1 == N ? '\n' : ' ');
        }
    }
    return 0;
}
