#include <bits/stdc++.h>
using namespace std;

class DigitDP {
public:
    string num;
    int digit, k;
    long long dp[20][20][2];

    long long dfs(int pos, int cnt, bool tight) {

        // More than k occurrences are useless
        if (cnt > k)
            return 0;

        // Finished building the number
        if (pos == num.size())
            return (cnt == k);

        if (dp[pos][cnt][tight] != -1)
            return dp[pos][cnt][tight];

        int limit = tight ? num[pos] - '0' : 9;

        long long ans = 0;

        for (int d = 0; d <= limit; d++) {
            ans += dfs(
                pos + 1,
                cnt + (d == digit),
                tight && (d == limit)
            );
        }

        return dp[pos][cnt][tight] = ans;
    }

    long long solve(long long x, int d, int kk) {

        if (x < 0)
            return 0;

        num = to_string(x);
        digit = d;
        k = kk;

        memset(dp, -1, sizeof(dp));

        return dfs(0, 0, true);
    }
};

int main() {

    long long a = 100;
    long long b = 500;

    int d = 2;
    int k = 2;

    DigitDP obj;

    cout << obj.solve(b, d, k) - obj.solve(a - 1, d, k);

    return 0;
}