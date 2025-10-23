#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int s, p, m, n;
vector<int> ds;

ll memo[1000005];

ll dp(int type) {
    if (type == n) return 0;

    ll &ans = memo[type];
    if (ans != -1) return ans;

    int ty = type;
    while (ty < n && m + ds[type] > ds[ty]) ty++;

    return ans = min(dp(type + 1) + s, dp(ty) + p);

} 


int main() {
    scanf("%d %d %d %d", &s, &p, &m, &n);
    ds.assign(n, 0);

    for (int i = 0; i < n; i++) {
        scanf("%d", &ds[i]);
    }

    memset(memo, -1, sizeof(memo));

    ll res = dp(0);

    printf("%ld\n", res);

    return 0;
}