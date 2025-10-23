#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> xs;
vector<int> ys;

long long memo[40][805][805];

long long inf = 1e19;

long long dp(int type, int x, int y) {
    if (type == n) return (x == 0 && y == 0);

    long long &ans = memo[type][x+402][y+402];
    if (ans != -1) return ans;

    return ans = dp(type + 1, x, y) + dp(type + 1, x + xs[type], y + ys[type]);
}

int main() {    
    scanf("%d", &n);

    xs.assign(n, 0);
    ys.assign(n, 0);
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &xs[i], &ys[i]);
    }

    memset(memo, -1, sizeof(memo));

    long long res = dp(0, 0, 0) - 1;
    printf("%ld\n", res);


    return 0;
}