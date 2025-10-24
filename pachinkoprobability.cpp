#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> AL;
vector<int> gates;
vector<int> p;

vector<pair<ll, ll>> memo; 

pair<ll, ll> cnt(int type) {
    if (gates[type] == 1) return {1, 1};
    if (AL[type].size() == 0) return {1, 0};

    auto &ans = memo[type];
    if (ans.first != -1) return ans;

    ans = {0, 0};
    for (int i: AL[type]) {
        auto [a, b] = cnt(i);
        ans = {ans.first + a, ans.second + b};
    }

    return ans;
}

// pair<ll, ll> cnt(int type) {

//     for (int i = 0; i < n; i++) if (p[i] == )
//     return ans;
// }

int main() {
    int n, m, k;
    scanf("%d %d", &n, &m);


    AL.assign(n, {});

    p.assign(n, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        AL[a].push_back(b);
        p[b]++;
    }

    scanf("%d", &k);
    gates.assign(n, 0);
    memo.assign(n, {-1, -1});

    for (int i = 0; i < k; i++) {
        int a;
        scanf("%d", &a);
        gates[a] = 1;
    }

    ll cntTot = 0, cntG = 0;

    for (int i = 0; i < n; i++) if (p[i] == 0) {
        auto [a, b] = cnt(i);
        cntTot += a;
        cntG += b;
    }

    printf("winning paths %ld\ntotal paths %ld\n", cntG, cntTot);
    
    


    return 0;
}