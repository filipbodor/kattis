#include <bits/stdc++.h>
using namespace std;

int INF = 10e9;

int main() {

    while (true) {
        int n, m, q;
        scanf("%d %d %d", &n, &m, &q);
        if (n == 0 && m == 0 && q == 0) break;

        vector<vector<int>> AM(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) AM[i][i] = 0;
        for (int i = 0; i < m; i++) {
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            AM[a][b] = min(AM[a][b], w);
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if(AM[j][i] < INF && AM[i][k] < INF) {
                        AM[j][k] = min(AM[j][k], AM[j][i] + AM[i][k]);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (AM[k][k] < 0 && AM[i][k] != INF && AM[k][j] != INF) AM[i][j] = -INF;
                }
            }
        }


        for (int i = 0; i < q; i++) {
            int x, z;
            scanf("%d %d", &x, &z);

            if (AM[x][z] == -INF) printf("-Infinity\n");
            else if (AM[x][z] == INF) printf("Impossible\n");
            else printf("%d\n", AM[x][z]);
        }

        printf("\n");
    }
}