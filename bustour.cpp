#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S))

vector<vector<int>> AM;
int dist[21][21];
int firstHalf[21];
int memofirst[21][(1 << 19)];
int memosec[21][(1 << 19)];
int p[21];
int n, m;

int inf = 1e9;

int tsp(int u, int s, int mask) {
    if (mask == 0) return AM[u][n - 1] + AM[u][0];

    int ans = 0;

    int &ans1 = memofirst[u][mask];
    if (ans1 != -1) ans += ans1;

    int &ans2 = memosec[u][mask];
    if (ans2 != -1) ans += ans2;

    if (ans1 != -1 && ans2 != -1) return ans;

    ans2 = ans1 = inf;

    int m = mask;
    while (m) {
        int two_pow_v = LSOne(m);
        int v = __builtin_ctz(two_pow_v)+1;
        int val = tsp(v, v, mask^two_pow_v);
        ans1 = min(ans1, AM[u][v] + val);
        ans2 = min(ans2, AM[s][v] + val);
        m -= two_pow_v;
    }


    return ans1 + ans2;
}


int main() {
    int idx = 1;
    while (scanf("%d %d", &n, &m) != EOF) {
        AM.assign(n, vector<int>(n, inf));
        memset(memofirst, -1, sizeof(memofirst));
        memset(memosec, -1, sizeof(memosec));
        for (int i = 0; i < n; i++) AM[i][i] = 0;

        for (int i = 0; i < m; i++) {
            int a, b, t;
            scanf("%d %d %d", &a, &b, &t);
            AM[a][b] = t;
            AM[b][a] = t;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    AM[j][k] = min(AM[j][k], AM[j][i] + AM[i][k]);
                }
            }
        }

        int mask = (1 << (n - 2)) - 1;
        int mi = tsp(0, n-1, mask);

        printf("Case %d: %d\n", idx, mi);

        idx++;
    }


    return 0;
}