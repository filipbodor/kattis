#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))

vector<vector<int>> con;

int memo[12][1 << 10];

int dp(int mask, int prev) {
    if (mask == 0) return con[prev][1];

    int &ans = memo[prev][mask];
    if (ans != -1) return ans;

    int ori = mask;
    ans = 0;
    while (ori) {

        int r = LSOne(ori);
        int ctz_r = __builtin_ctz(r) + 2;

        if (con[prev][ctz_r]) ans += dp(mask^r, ctz_r);

        ori -= r;
    }

    return ans;
}

int main() {
    int T, idx = 1;
    scanf("%d", &T);

    while (T--) {
        int n, k;
        scanf("%d %d", &n, &k);

        con.assign(n+1, vector<int>(n+1, 1));
        memset(memo, -1, sizeof(memo));

        for (int i = 0; i < k; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            con[a][b] = 0;
            con[b][a] = 0;
        }

        int counter = dp((1 << (n-1)) - 1, 1);

        counter = (counter / 2) % 9901;

        printf("Case #%d: %d\n", idx, counter);

        idx++;
    }

    return 0;
}