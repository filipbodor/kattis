#include <bits/stdc++.h>
using namespace std;

int tiles[40];
int mem[40][40][10100];

int comb(int m, int n) {
    long long res = 1;
    for (int i = 1; i <= n; ++i) {
        res = res * (m - i + 1) / i;
    }
    return (int)res;
}

int countWays(int diff, int idx, int m, int n) {
    if (diff == 0 && n == 0) return 1;
    if ((idx == m) || (n == 0) || (diff < 0)) return 0;

    int &ans = mem[idx][n][diff];
    if (ans != -1) return ans;

    return ans = countWays(diff - tiles[idx], idx + 1, m, n - 1) + countWays(diff, idx + 1, m, n);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        int n, m, t;
        scanf("%d", &m);

        

        for (int j = 0; j < m; j++) {
            scanf("%d", &tiles[j]);
        }

        scanf("%d %d", &n, &t);

        memset(mem, -1, sizeof(mem));

        int ans = countWays(t, 0, m, n);

        int all = comb(m, n);

        printf("Game %d -- %d : %d\n", i, ans, all - ans);


    }

    return 0;
}