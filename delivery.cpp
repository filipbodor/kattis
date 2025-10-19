#include <bits/stdc++.h>
using namespace std;

int memo[1001][10001];

int dp(int type, int diff, vector<pair<int, int>> &a, int &k, int &n) {
    if (type == n) {
        if (diff == 0) return 0;
        else return a[type - 1].first * 2;
    }

    //printf("%d %d\n", type, diff);

    int &ans = memo[type][diff];
    if (ans != -1) return ans;

    if (diff > a[type].second) {
        return ans = min(a[type].first * 2 + dp(type + 1, 0, a, k, n), dp(type + 1, diff - a[type].second, a, k, n));
    }

    if (diff == a[type].second) {
        return ans = a[type].first * 2 + dp(type + 1, 0, a, k, n);
    }

    int adder = 0;
    if (diff > 0) adder = a[type].first * 2;
    
    int pl1 = ceil((double)(a[type].second - diff) / (double)(k)) * a[type].first * 2;
    int pl2 = ((a[type].second - diff) / k) * a[type].first * 2;
    int diff2 = (k - ((a[type].second - diff) % k)) % k;

    //printf("pl1: %d, pl2: %d, diff2: %d\n", pl1, pl2, diff2);

    return ans = min(adder + pl1 + dp(type + 1, 0, a, k, n), adder + pl2 + dp(type + 1, diff2, a, k, n));
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<pair<int, int>> les {};
    vector<pair<int, int>> more {};

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a < 0) les.push_back({a * -1, b});
        else more.push_back({a, b});
    }

    sort(les.begin(), les.end());
    sort(more.begin(), more.end());

    int size1 = les.size();
    memset(memo, -1, sizeof(memo));
    int res1 = dp(0, 0, les, k, size1);

    int size2 = more.size();
    memset(memo, -1, sizeof(memo));
    int res2 = dp(0, 0, more, k, size2);

    printf("%d\n", res1 + res2);

    return 0;
}