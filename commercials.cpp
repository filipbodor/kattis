#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p;
    scanf("%d %d", &n, &p);

    vector<int> studs(n);
    for (int &i : studs) {
        scanf("%d", &i);
    }

    vector<long long> dp(n+1, 0);

    long long ma = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i], dp[i-1] + studs[i-1] - p);
        ma = max(ma, dp[i]);
    }

    printf("%ld\n", ma);

    return 0;
}