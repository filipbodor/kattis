#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> visited;
vector<vector<int>> grid;

vector<pair<int, int>> axes {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dfs(int a, int b) {
    visited[a][b] = 1;
    int counter = 0;

    for (auto &[p, q] : axes) {
        int pa = p + a, pb = q + b;

        if (pa >= 0 && pa < n && pb >= 0 && pb < m) {
            if (grid[pa][pb]) {counter++;}
            else if (visited[pa][pb] == -1) counter += dfs(pa, pb);
        }
    }

    return counter;
}

int getSurr(int a, int b) {
    int counter = 0;
    counter += (a == 0);
    counter += (a == n-1);
    counter += (b == 0);
    counter += (b == m-1);
    return counter;
}

int main() {
    scanf("%d %d", &n, &m);

    grid.assign(n, vector<int>(m));
    visited.assign(n, vector<int>(m, -1));
    vector<vector<int>> starts_vis(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char a;
            scanf(" %c", &a);
            grid[i][j] = a - '0';
        }
    }

    vector<pair<int, int>> starts {};
    for (int i = 0; i < n; i++) {
        if (starts_vis[i][0] == -1) {
            starts_vis[i][0] = 1;
            starts.push_back({i, 0});
        }
        if (starts_vis[i][m-1] == -1) {
            starts_vis[i][m-1] = 1;
            starts.push_back({i, m-1});
        }
    }
    for (int i = 1; i < m-1; i++) {
        if (starts_vis[0][i] == -1) {
            starts_vis[0][i] = 1;
            starts.push_back({0, i});
        }
        if (starts_vis[n-1][i] == -1) {
            starts_vis[n-1][i] = 1;
            starts.push_back({n-1, i});
        }
    }

    int counter = 0;
    for (auto &[a, b] : starts) {
        if (visited[a][b] == -1 && !grid[a][b]) {
            counter += dfs(a, b);
        }
        if (grid[a][b]) {
            counter += getSurr(a, b);
        }
    }
    
    printf("%d\n", counter);

    return 0;
}