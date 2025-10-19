#include <bits/stdc++.h>
using namespace std;

// Coins must be strictly decreasing: c[0] > c[1] > ... > c[n-1], with c[n-1] = 1.

// Greedy representation vector for amount x (using descending coins).
// Returns vector counts of size n; also fills out total coin count if requested.
static inline vector<int> greedyVector(const vector<int>& c, int x, int* outCount = nullptr) {
    int n = (int)c.size();
    vector<int> v(n, 0);
    int cnt = 0;
    for (int k = 0; k < n; ++k) {
        if (x <= 0) break;
        if (c[k] <= x) {
            v[k] = x / c[k];
            x -= v[k] * c[k];
            cnt += v[k];
        }
    }
    if (outCount) *outCount = cnt;
    return v;
}

// Dot product V·C
static inline int valueOf(const vector<int>& v, const vector<int>& c) {
    long long s = 0;
    for (size_t i = 0; i < v.size(); ++i) s += 1LL * v[i] * c[i];
    return (int)s; // safe: w < c1 + c2 per bounds in the theorem
}

// Sum of entries |V|
static inline int weight(const vector<int>& v) {
    long long s = 0;
    for (int x : v) s += x;
    return (int)s;
}

// Pearson O(n^3) canonicality test
// Returns {isCanonical, counterexampleW (or -1 if none)}
pair<bool,int> canonical_pearson(vector<int> coins_desc) {
    // Remove duplicates and ensure descending
    sort(coins_desc.begin(), coins_desc.end());
    coins_desc.erase(unique(coins_desc.begin(), coins_desc.end()), coins_desc.end());
    sort(coins_desc.rbegin(), coins_desc.rend());

    int n = (int)coins_desc.size();
    if (n == 0 || coins_desc.back() != 1) {
        // Without a 1-coin, not all amounts are representable; canonicality is ill-defined.
        // Most problems treat that as "non-canonical".
        return {false, -1};
    }

    // Indices in the paper are 1-based. Here we use 0-based:
    // c[0] = c1 (largest), ..., c[n-1] = cn (smallest = 1).
    const auto& c = coins_desc;

    // For each i = 2..n (1-based)  -> i0 = 1..n-1 (0-based), we need V = G(c_{i-1} - 1)
    for (int i0 = 1; i0 <= n - 1; ++i0) {
        int amount = c[i0 - 1] - 1;            // c_{i-1} - 1
        if (amount < 0) continue;              // safety
        vector<int> V = greedyVector(c, amount);

        // For each j = i..n (1-based) -> j0 = i0..n-1 (0-based)
        for (int j0 = i0; j0 < n; ++j0) {
            // Build M = (v1..v_{j-1}, v_j+1, 0..0)
            vector<int> M = V;
            for (int k = j0 + 1; k < n; ++k) M[k] = 0;
            M[j0] = V[j0] + 1;

            int w = valueOf(M, c);

            // Compute greedy coin count for w
            int greedyCnt = 0;
            greedyVector(c, w, &greedyCnt);

            // Compare sizes: if |M| < |G(w)|, we found a counterexample
            int mSize = weight(M);
            if (mSize < greedyCnt) {
                return {false, w};
            }
        }
    }

    return {true, -1};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) cin >> coins[i];

    auto [ok, w] = canonical_pearson(coins);
    if (ok) {
        cout << "canonical\n";
    } else {
        if (w >= 0) {
            cout << "non-canonical\n";
        } else {
            cout << "non-canonical\n";
        }
    }
    return 0;
}
