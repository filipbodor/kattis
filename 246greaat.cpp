#include <bits/stdc++.h>
using namespace std;

#define INF 10e15
typedef long long ll;

unordered_map<int, int> p;
unordered_map<int, ll> memo;
vector<ll> S;
vector<ll> D;
int N;
ll minimal = 10e15;

ll dp(ll dif, int rem) {
    printf("%d %d %d, ", dif, rem, minimal);
    if (dif >= minimal) return 10e15;
    if (rem == 0) {
        minimal = min(minimal, dif);
        return memo[rem] = dif;
    }
    auto it = memo.find(rem);
    if (it != memo.end()) return it->second;

    ll ans = 10e15;
    for (int i = 0; i <= N; i++) {
        ll a = dp(dif + D[i], rem - S[i]);
        if (a < ans) {
            ans = a;
            p[rem] = i;
        }
    }
    memo[rem] = ans;
    minimal = ans; 
    return ans;
}

int main() {
    int T;
    scanf("%d %d", &N, &T);

    S.assign(N+1, 0);
    D.assign(N+1, 0);
    S[0] = 1;
    D[0] = 1;

    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &S[i], &D[i]);
    }

    ll res = dp(0, T);

    vector<int> seq (200000);
    int n = 0;

    int r = T;

    while (r != 0) {
        int ch = p[r];
        seq[n] = ch + 1;
        r -= S[ch];
        n++;
    }

    printf("%d\n", n);
    for (int i = 0; i < n; i++) printf("%d ", seq[i]);

    return 0;
}