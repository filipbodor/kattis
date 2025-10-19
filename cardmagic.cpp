#include <bits/stdc++.h>
using namespace std;

int mod = 1000000009;

int memo[100][5000];
int N, K, T;

int dp(int type, int diff) {
    if (type == N) {
        if (diff == T) return 1;
        return 0;
    }

    int &ans = memo[type][diff];
    if (ans != -1) return ans;

    ans = 0;

    for (int i = 1; i <= K; i++) {
        ans = (ans + dp(type + 1, diff + i)) % mod;
    }

    return ans;

}

int main() {
    scanf("%d %d %d", &N, &K, &T);

    memset(memo, -1, sizeof(memo));

    int a = dp(0, 0);

    printf("%d\n", a);

    return 0;
}