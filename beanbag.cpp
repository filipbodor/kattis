#include <bits/stdc++.h>
using namespace std;

int n, t;
vector<int> beans;
vector<int> AM;
int OK;

int backtrack(int type, int mask) {
    //printf("%d %d %d\n", type, mask, OK);
    if (type == t) return 0;

    if ((AM[type] & mask) != 0) {
        return backtrack(type + 1, mask);
    }
    int ans = 1e8;
    int m = (AM[type] | mask) ^ (mask);
    while (m) {
        int r = m & -(m);
        int v = __builtin_ctz(r);
        
        ans = min(ans, beans[v] + backtrack(type + 1, mask | r));
        m -= r;
    }
    return ans;
}

int main() {

    scanf("%d", &n);
    beans.assign(n, 0);
    int tot = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &beans[i]);
        tot += beans[i];
    }
    scanf("%d", &t);
    AM.assign(t, 0);
    for (int i = 0; i < t; i++) {
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            int a;
            scanf("%d", &a);
            AM[i] |= 1 << (a-1);
        }
    }

    OK = (1 << n) - 1;

    int res = backtrack(0, 0);
    int ans = tot - res;
    printf("%d\n", ans);


    

    return 0;
}