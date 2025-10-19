#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;
int h, w;

vector<pair<int, int>> axes {{1, -1}, {1, 0}, {1, 1}, {0, -1}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}};

void dj() {
    vector<vector<int>> dist(h, vector<int>(w, 1e9));
    vector<vector<pair<int, int>>> parent(h, vector<pair<int, int>>(w));

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < w; i++) {
        pq.push({grid[0][i], {0, i}});
        dist[0][i] = grid[0][i];
        parent[0][i] = {-1, -1};
    }

    while (!pq.empty()) {
        auto a = pq.top(); pq.pop();

        if (a.second.first == h - 1) continue;

        for (auto &[p, q] : axes) {
            int ap = a.second.first + p, aq = a.second.second + q;

            if (aq >= 0 && aq < w && ap >= 0 && ap < h) {
                if (a.first + grid[ap][aq] < dist[ap][aq]) {
                    parent[ap][aq] = {a.second.first, a.second.second};
                    dist[ap][aq] = a.first + grid[ap][aq];
                    pq.push({dist[ap][aq], {ap, aq}});
                }
            }
        }
    }

    pair<int, int> mi = {-1, 1e9};
    for (int i = 0; i < w; i++) {
        if (dist[h - 1][i] < mi.second) {
            mi = {i, dist[h - 1][i]};
        }
    }

    vector<vector<int>> way(h, vector<int>(w, 0));
    int idx = mi.first;

    pair<int, int> cur = {h - 1, idx};
    
    while (cur.first != -1){
        way[cur.first][cur.second] = 1;
        cur = parent[cur.first][cur.second];
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (way[i][j] == 1) printf(" ");
            else printf("%d", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    while (scanf("%d %d", &h, &w) == 2 && !(h == 0 && w == 0)) {
        grid.assign(h, vector<int>(w));

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char c;
                scanf(" %c", &c);
                grid[i][j] = (int)(c - '0');
            }
        }

        dj();

    }

    return 0;
}