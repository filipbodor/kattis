#include <bits/stdc++.h>
using namespace std;

int m, S;
vector<int> info;
vector<int> conv;

int memo[301][301];

int bfs() {

    for (int i = 0; i <= 300; i++) for (int j = 0; j <= 300; j++) memo[i][j] = 1e9;
    queue<pair<int, int>> q;
    q.push({0, 0});
    memo[0][0] = 0;

    while (!q.empty()) {
        auto &[a, b] = q.front(); q.pop();

        for (int i = 0; i < m; i++) {
            double val = hypot(a + conv[i], b + info[i]);
            if (val == S) return memo[a][b] + 1;
            if (val < S && memo[a + conv[i]][b + info[i]] > memo[a][b] + 1) {
                memo[a + conv[i]][b + info[i]] = memo[a][b] + 1;
                q.push({a + conv[i], b + info[i]});
            }
        }
    }
    
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m, &S);

        info.assign(m, 0);
        conv.assign(m, 0);

        for (int j = 0; j < m; j++) {
            scanf("%d %d", &conv[j], &info[j]);
        }

        int ans = bfs();

        if (ans == -1) {
            printf("not possible\n");
        } else {
            printf("%d\n", ans);
        }

    }

    return 0;
}




