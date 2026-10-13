```cpp
// ================= STRING ALGORITHMS =================


// =====================================================
// KMP SEARCH
//
// Find all occurrences of pattern in text.
//
// Time: O(n + m)
//
// You already have prefix_function() above.
// =====================================================

vector<int> kmp_search(
    string text,
    string pattern
) {

    vector<int> pi = prefix_function(pattern);

    vector<int> occurrences;

    int n = text.size();
    int m = pattern.size();

    int j = 0;

    for (int i = 0; i < n; i++) {

        while (j > 0 &&
               text[i] != pattern[j]) {

            j = pi[j - 1];
        }

        if (text[i] == pattern[j])
            j++;

        if (j == m) {

            occurrences.push_back(
                i - m + 1
            );

            j = pi[j - 1];
        }
    }

    return occurrences;
}


// =====================================================
// MANACHER'S ALGORITHM
//
// Finds palindrome radii.
//
// d1[i] = radius of odd-length palindrome
//         centered at i.
//
// d2[i] = radius of even-length palindrome
//         centered between i-1 and i.
//
// =====================================================

vector<int> manacher_odd(string s) {

    int n = s.size();

    vector<int> d1(n);

    int l = 0;
    int r = -1;

    for (int i = 0; i < n; i++) {

        int k =
            (i > r ? 1 :
             min(d1[l + r - i], r - i + 1));

        while (
            i - k >= 0 &&
            i + k < n &&
            s[i - k] == s[i + k]
        ) {
            k++;
        }

        d1[i] = k--;

        if (i + k > r) {

            l = i - k;
            r = i + k;
        }
    }

    return d1;
}


// =====================================================
// EVEN LENGTH MANACHER
// =====================================================

vector<int> manacher_even(string s) {

    int n = s.size();

    vector<int> d2(n);

    int l = 0;
    int r = -1;

    for (int i = 0; i < n; i++) {

        int k =
            (i > r ? 0 :
             min(d2[l + r - i + 1],
                 r - i + 1));

        while (
            i + k < n &&
            i - k - 1 >= 0 &&
            s[i + k] == s[i - k - 1]
        ) {
            k++;
        }

        d2[i] = k--;

        if (i + k > r) {

            l = i - k - 1;
            r = i + k;
        }
    }

    return d2;
}


// =====================================================
// ROLLING HASH
//
// Useful for:
//
// - substring equality
// - pattern matching
// - palindrome checking
//
// Double hash can be used if collision risk matters.
//
// =====================================================

struct RollingHash {

    static const int HASH_MOD = 1000000007;
    static const int BASE = 911382323;

    vector<int> pref;
    vector<int> power_base;

    RollingHash(string s) {

        int n = s.size();

        pref.resize(n + 1);
        power_base.resize(n + 1);

        power_base[0] = 1;

        for (int i = 0; i < n; i++) {

            pref[i + 1] =
                (pref[i] * BASE +
                 s[i]) % HASH_MOD;

            power_base[i + 1] =
                power_base[i] * BASE %
                HASH_MOD;
        }
    }


    // Hash of substring [l, r]
    int get(int l, int r) {

        int ans =
            pref[r + 1] -
            pref[l] * power_base[r - l + 1] %
            HASH_MOD;

        if (ans < 0)
            ans += HASH_MOD;

        return ans;
    }
};


// =====================================================
// DOUBLE ROLLING HASH
// =====================================================

struct DoubleHash {

    static const int MOD1 = 1000000007;
    static const int MOD2 = 1000000009;

    static const int BASE = 911382323;

    vector<int> h1, h2;
    vector<int> p1, p2;


    DoubleHash(string s) {

        int n = s.size();

        h1.resize(n + 1);
        h2.resize(n + 1);

        p1.resize(n + 1);
        p2.resize(n + 1);

        p1[0] = p2[0] = 1;

        for (int i = 0; i < n; i++) {

            h1[i + 1] =
                (h1[i] * BASE + s[i])
                % MOD1;

            h2[i + 1] =
                (h2[i] * BASE + s[i])
                % MOD2;

            p1[i + 1] =
                p1[i] * BASE % MOD1;

            p2[i + 1] =
                p2[i] * BASE % MOD2;
        }
    }


    pair<int,int> get(int l, int r) {

        int x1 =
            h1[r + 1] -
            h1[l] * p1[r - l + 1] %
            MOD1;

        int x2 =
            h2[r + 1] -
            h2[l] * p2[r - l + 1] %
            MOD2;

        if (x1 < 0)
            x1 += MOD1;

        if (x2 < 0)
            x2 += MOD2;

        return {x1, x2};
    }
};


// =====================================================
// TRIE
//
// Useful for:
//
// - Prefix queries
// - Dictionary
// - XOR problems (use BinaryTrie separately)
// =====================================================

struct Trie {

    struct Node {

        int child[26];

        bool terminal;

        Node() {

            fill(child, child + 26, -1);

            terminal = false;
        }
    };


    vector<Node> trie;


    Trie() {

        trie.push_back(Node());
    }


    void insert(string s) {

        int node = 0;

        for (char c : s) {

            int x = c - 'a';

            if (trie[node].child[x] == -1) {

                trie[node].child[x] =
                    trie.size();

                trie.push_back(Node());
            }

            node = trie[node].child[x];
        }

        trie[node].terminal = true;
    }


    bool search(string s) {

        int node = 0;

        for (char c : s) {

            int x = c - 'a';

            if (trie[node].child[x] == -1)
                return false;

            node = trie[node].child[x];
        }

        return trie[node].terminal;
    }


    bool starts_with(string s) {

        int node = 0;

        for (char c : s) {

            int x = c - 'a';

            if (trie[node].child[x] == -1)
                return false;

            node = trie[node].child[x];
        }

        return true;
    }
};


// =====================================================
// AHO-CORASICK
//
// Multiple pattern matching.
//
// Useful when:
//
// text is large
// AND
// many patterns need to be searched.
//
// Complexity:
// O(total pattern length + text length + matches)
// =====================================================

struct AhoCorasick {

    static const int ALPHA = 26;

    struct Node {

        int next[ALPHA];

        int link;

        vector<int> output;

        Node() {

            fill(next, next + ALPHA, -1);

            link = 0;
        }
    };


    vector<Node> trie;


    AhoCorasick() {

        trie.push_back(Node());
    }


    void add_string(
        string s,
        int id
    ) {

        int node = 0;

        for (char c : s) {

            int x = c - 'a';

            if (trie[node].next[x] == -1) {

                trie[node].next[x] =
                    trie.size();

                trie.push_back(Node());
            }

            node = trie[node].next[x];
        }

        trie[node].output.push_back(id);
    }


    void build() {

        queue<int> q;

        for (int c = 0; c < ALPHA; c++) {

            int v = trie[0].next[c];

            if (v != -1) {

                trie[v].link = 0;

                q.push(v);

            } else {

                trie[0].next[c] = 0;
            }
        }


        while (!q.empty()) {

            int v = q.front();

            q.pop();

            int link = trie[v].link;

            for (int id : trie[link].output)
                trie[v].output.push_back(id);


            for (int c = 0; c < ALPHA; c++) {

                int u = trie[v].next[c];

                if (u != -1) {

                    trie[u].link =
                        trie[link].next[c];

                    q.push(u);

                } else {

                    trie[v].next[c] =
                        trie[link].next[c];
                }
            }
        }
    }
};


// =====================================================
// SUFFIX ARRAY
//
// Useful for:
//
// - Lexicographic suffix ordering
// - Number of distinct substrings
// - LCP problems
//
// O(n log n)
//
// =====================================================

vector<int> suffix_array(string s) {

    s += char(0);

    int n = s.size();

    vector<int> p(n), c(n);

    {
        vector<pair<char,int>> a(n);

        for (int i = 0; i < n; i++)
            a[i] = {s[i], i};

        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++)
            p[i] = a[i].second;

        c[p[0]] = 0;

        for (int i = 1; i < n; i++) {

            c[p[i]] =
                c[p[i - 1]] +
                (a[i].first !=
                 a[i - 1].first);
        }
    }


    int k = 0;

    while ((1LL << k) < n) {

        for (int i = 0; i < n; i++) {

            p[i] -= (1LL << k);

            if (p[i] < 0)
                p[i] += n;
        }


        // Counting sort
        vector<int> cnt(n);

        for (int x : c)
            cnt[x]++;

        vector<int> pos(n);

        for (int i = 1; i < n; i++)
            pos[i] =
                pos[i - 1] +
                cnt[i - 1];


        vector<int> p_new(n);

        for (int x : p)
            p_new[pos[c[x]]++] = x;

        p = p_new;


        vector<int> c_new(n);

        c_new[p[0]] = 0;

        for (int i = 1; i < n; i++) {

            pair<int,int> prev = {
                c[p[i - 1]],
                c[(p[i - 1] + (1LL << k)) % n]
            };

            pair<int,int> now = {
                c[p[i]],
                c[(p[i] + (1LL << k)) % n]
            };

            c_new[p[i]] =
                c_new[p[i - 1]] +
                (now != prev);
        }

        c = c_new;

        k++;
    }


    // Remove sentinel
    p.erase(p.begin());

    return p;
}


// =====================================================
// LCP ARRAY
//
// Kasai algorithm.
//
// Given suffix array.
//
// lcp[i] = LCP(sa[i], sa[i+1])
//
// O(n)
// =====================================================

vector<int> lcp_array(
    string s,
    vector<int>& sa
) {

    int n = s.size();

    vector<int> rank(n);

    for (int i = 0; i < n; i++)
        rank[sa[i]] = i;

    vector<int> lcp(n - 1);

    int k = 0;

    for (int i = 0; i < n; i++) {

        int r = rank[i];

        if (r == n - 1) {

            k = 0;
            continue;
        }

        int j = sa[r + 1];

        while (
            i + k < n &&
            j + k < n &&
            s[i + k] == s[j + k]
        ) {
            k++;
        }

        lcp[r] = k;

        if (k)
            k--;
    }

    return lcp;
}


// =====================================================
// NUMBER OF DISTINCT SUBSTRINGS
//
// n*(n+1)/2 - sum(LCP)
//
// =====================================================

int distinct_substrings(
    string s
) {

    int n = s.size();

    if (n == 0)
        return 0;

    vector<int> sa =
        suffix_array(s);

    vector<int> lcp =
        lcp_array(s, sa);

    int total =
        n * (n + 1) / 2;

    for (int x : lcp)
        total -= x;

    return total;
}
```