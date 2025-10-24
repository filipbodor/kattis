#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<pair<int, int>> rows;

int memo[201][201][2][2];

int dp(int type, int closed, int left, int right) {
    //printf("%d %d %d %d\n", type, closed, left, right);
    if (n == type) return closed == k ? 0 : 1e9;
    if (closed > k) return 1e9;

    int &ans = memo[type][closed][left][right];
    if (ans != -1) return ans;

    ans = dp(type + 1, closed, 0, 0);

    if (right == 0) {
        ans = min(ans, rows[type].first + dp(type + 1, closed + 1, 1, 0));
    }
    if (left == 0) {
        ans = min(ans, rows[type].second + dp(type + 1, closed + 1, 0, 1));
    }

    return ans;

}

int main() { 
    while (scanf("%d %d", &n, &k) == 2 && !(n == 0 && k == 0)) {

        rows.assign(n, {});
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            rows[i] = {a, b};
            cnt += a + b;
        }

        memset(memo, -1, sizeof(memo));

        int ans = cnt - dp(0, 0, 0, 0);
        printf("%d\n", ans);
    }

    return 0;
}