#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<pair<int, int>> axes {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

vector<vector<int>> grid;

void dfs(int a, int b) {
    grid[a][b] = 1;
    for (auto &[p, q] : axes) {
        if (p + a >= 0 && p + a < n && q + b >= 0 && q + b < m && grid[p+a][q+b] == 0) {
            dfs(p+a, q+b);
        } 
    }
}

int main() {
    int idx = 1;
    while (scanf("%d %d", &n, &m) != EOF) {

        grid.assign(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char a;
                scanf(" %c", &a);
                grid[i][j] = (a == '#');
            }
        }
        int counter = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) if (grid[i][j] == 0) {
                dfs(i, j);
                counter++;
            }
        }

        printf("Case %d: %d\n", idx, counter);
        idx++;
    }

    return 0;
}