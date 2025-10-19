#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
vector<vector<int>> visited;
vector<vector<int>> anses;
int h, w;

vector<pair<int, int>> axes {{-1, 1}, {0, 1}, {1, 1}, {-1, 0}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

long long dfs(int a, int b, int ma) {

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ma, {a, b}});

    long long counter = 0;

    while (!pq.empty()) {
        auto u = pq.top(); pq.pop();
        //printf("%d %d %d +(%d %d)\n", u.second.first, u.second.second, u.first, -max(u.first, grid[u.second.first][u.second.second]), anses[u.second.first][u.second.second]);

        if (-max(u.first, grid[u.second.first][u.second.second]) <= anses[u.second.first][u.second.second]) continue;
        
        counter += -max(u.first, grid[u.second.first][u.second.second]) - anses[u.second.first][u.second.second];

        anses[u.second.first][u.second.second] = -max(u.first, grid[u.second.first][u.second.second]);

        //visited[u.second.first][u.second.second] = 1;

        for (auto &[p, q] : axes) {
            int pa = p + u.second.first, qb = q + u.second.second;
            if (pa >= 0 && pa < h && qb >= 0 && qb < w && grid[pa][qb] < 0) {
                //visited[pa][qb] = 0;
                pq.push({max(u.first, grid[pa][qb]), {pa, qb}});
            } 
        }
    }

    // for (int i = 0; i < h; i++) {
    //     for (int j = 0; j < w; j++) {
    //         printf("%d ", anses[i][j]);
    //     }
    //     printf("\n");
    // }
    // counter = 0;
    // for (int i = 0; i < h; i++) {
    //     for (int j = 0; j < w; j++) {
    //         counter += anses[i][j];
    //     }
    // }

    return counter;
}

int main() {
    scanf("%d %d", &h, &w);

    grid.assign(h, vector<int>(w));
    visited.assign(h, vector<int>(w, -1));
    anses.assign(h, vector<int>(w, 0));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;

    long long res = dfs(a, b, grid[a][b]);

    printf("%ld\n", res);


    return 0;
}