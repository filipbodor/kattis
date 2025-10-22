#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> grid;
vector<pair<int, int>> axes {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

unordered_map<int, int> rest {{0, 2}, {1, 3}, {2, 0}, {3, 1}, {4, 4}};

int memo[5][3][1001][1001];

int bfs(pair<int, int> start, pair<int, int> dest) {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{4, 0}, {start.first, start.second}});

    int res = 1e9;
    memset(memo, -1, sizeof(memo));

    while (!q.empty()) {
        auto &[aa, b] = q.front(); q.pop();
        auto &[a, ab] = aa;

        //printf("%d %d\n", b.first, b.second);

        if (b == dest) return memo[a][ab][b.first][b.second] + 1;

        for (int i = 0; i < 4; i++) if (!(a == i && ab == 2) && i != rest[a]) {
            auto &[p, qq] = axes[i];
            int bp = b.first + p, bq = b.second + qq;
            //int bp2 = b.first + 2 * p, bq2 = b.second + 2 * qq;
            int abb = (a == i) ? ab + 1 : 1;

            if (bp >= 0 && bp < n && bq >= 0 && bq < m && grid[bp][bq] == '.' && (memo[i][abb][bp][bq] == -1 || memo[i][abb][bp][bq] > memo[a][ab][b.first][b.second] + 1)) {
                memo[i][abb][bp][bq] = memo[a][ab][b.first][b.second] + 1;
                q.push({{i, abb}, {bp, bq}});
            }
            // if (bp2 >= 0 && bp2 < n && bq2 >= 0 && bq2 < m && grid[bp2][bq2] == '.' && (memo[i][bp2][bq2] == -1 || memo[i][bp2][bq2] > memo[a][b.first][b.second] + 2) && grid[bp][bq] == '.') {
            //     memo[i][bp2][bq2] = memo[a][b.first][b.second] + 2;
            //     q.push({i, {bp2, bq2}});
            // }
        }

    }
    return -1;


}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf(" %d %d", &n, &m);
        grid.assign(n, vector<char>(m));

        pair<int, int> r;
        pair<int, int> f;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf(" %c", &grid[i][j]);
                if (grid[i][j] == 'R') {
                    grid[i][j] = '.';
                    r = {i, j};
                } else if (grid[i][j] == 'D') {
                    grid[i][j] = '.';
                    f = {i, j};
                }
            }
        }

        int res = bfs(r, f);
        printf("%d\n", res);



    }

    return 0;
}