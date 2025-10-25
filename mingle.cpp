#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;

ll modpow(ll a, ll e) {
    a %= MOD;
    ll res = 1;
    while (e > 0) {
        if (e & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k;
    if (!(cin >> n >> k)) return 0;

    ll s = 2*k + 1;
    ll exp = s - 1;

    ll num = modpow((s - 1) % MOD, exp);
    ll den = modpow(s % MOD, exp);
    ll denInv = modpow(den, MOD - 2);

    ll ans = (n % MOD) * num % MOD;
    ans = ans * denInv % MOD;

    cout << ans << "\n";
    return 0;
}