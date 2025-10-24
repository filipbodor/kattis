#include <bits/stdc++.h>
using namespace std;

double AM[21][21];

double memo[1 << 21];

double dp(int mask, int u) {
    //printf("%d %d\n", mask, u);
    if (!mask) return 0;

    double &ans = memo[mask];
    if (ans != 0) return ans;

    ans = 1e9;
    int m = mask;

    while (m) {
        int pr = (m) & -(m);
        int ctz = __builtin_ctz(pr);

        int mm = mask^m;
        
        if (!mm) {
            ans = min(ans, AM[0][ctz] + dp(mask^pr, ctz) + AM[0][ctz]);
        }

        while (mm) {
            int prr = (mm) & -(mm);
            int ctzr = __builtin_ctz(prr);

            ans = min(ans, AM[0][ctz] + AM[ctz][ctzr] + dp(mask^pr^prr, ctzr) + AM[0][ctzr]);

            mm ^= prr;
        }

        m ^= pr;
    }
    
    return ans;

}

int main() {
    double x, y;
    int n;
    scanf("%lf %lf %d", &x, &y, &n);

    vector<pair<double, double>> poses(n+1);
    poses[0] = {x, y};

    for (int i = 1; i <= n; i++) {
        double a, b;
        scanf("%lf %lf", &a, &b);
        poses[i] = {a, b};
    }  

    memset(AM, 0, sizeof(AM));
    memset(memo, 0, sizeof(memo));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            AM[i][j] = hypot(poses[i].first - poses[j].first, poses[i].second - poses[j].second);
        }
    }

    double ma = -1;
    for (int i = 1; i <= n; i++) {
        ma = max(ma, AM[0][i]);
    }

    double ans = dp((1 << n + 1) - 1, 0) - ma;
    printf("%lf\n", ans);

    return 0;
}