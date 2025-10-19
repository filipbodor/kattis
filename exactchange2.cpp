#include <bits/stdc++.h>
using namespace std;

int a, n;
vector<int> ts;
int memo[102][20002];

int dp(int type, int diff) {
    if (diff > 20000) return 1e9;

    int &ans = memo[type][diff];
    if (ans != -1) return ans;

    if (type == n) return ans = diff >= a ? 0 : 1e9;
    
    return ans = min(1 + dp(type + 1, diff + ts[type]), dp(type + 1, diff));
}


int memo2[102][20002];


int dp2(int type, int diff, int re) {
    if (diff > re) return 1e9;
    if (type == n) return diff == re ? 0 : 1e9;

    int &ans = memo2[type][diff];
    if (ans != -1) return ans;
    
    return ans = min(1 + dp2(type + 1, diff + ts[type], re), dp2(type + 1, diff, re));
}



int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &a, &n);
        ts.assign(n, 0);

        for (int i = 0; i < n; i++) {
            scanf("%d", &ts[i]);
        }
        sort(ts.begin(), ts.end());

        memset(memo, -1, sizeof(memo));
        memset(memo2, -1, sizeof(memo2));

        dp(0, 0);

        int i;
        for (i = a; i < 20000 && memo[n][i] == -1; i++);

        int ans = dp2(0, 0, i);
        
        printf("%d %d\n", i, ans);

    }

    return 0;
}