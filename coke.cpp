#include <bits/stdc++.h>
using namespace std;

int memo[151][150][50];
int C;
int tot;

int dp(int cnt, int a, int b) {
    if (cnt == C) return 0;

    int &ans = memo[cnt][a][b];
    if (ans != -1) return ans;

    int c = tot - a * 5 - b * 10 - cnt * 8;

    ans = 1e9;
    if (b >= 1 && c >= 3) {
        ans = min(ans, 4 + dp(cnt + 1, a + 1, b - 1));
    }
    if (b >= 1) {
        ans = min(ans, 1 + dp(cnt + 1, a, b - 1));
    }
    if (a >= 2) {
        ans = min(ans, 2 + dp(cnt + 1, a - 2, b));
    }
    if (a >= 1 && c >= 3) {
        ans = min(ans, 4 + dp(cnt + 1, a - 1, b));
    }
    if (c >= 8) {
        ans = min(ans, 8 + dp(cnt + 1, a, b));
    }

    return ans;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n1, n5, n10;
        scanf("%d %d %d %d", &C, &n1, &n5, &n10);

        memset(memo, -1, sizeof(memo));

        tot = n1 + n5 * 5 + n10 * 10;
        int res = dp(0, n5, n10);

        printf("%d\n", res);
    }

    return 0;
}