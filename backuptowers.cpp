#include <bits/stdc++.h>
using namespace std;

int r, c, n;
vector<vector<int>> l1;
vector<vector<int>> l2;
vector<vector<int>> dist1;
vector<vector<int>> dist2;

vector<pair<int, int>> axes {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void bfs2(vector<pair<int, int>> &points) {
    queue<pair<pair<int, int>, pair<int, int>>> q;

    for (int i = 0; i < n; i++) {
        dist2[points[i].first][points[i].second] = 0;
        q.push({{i+1, 0}, {points[i].first, points[i].second}});
    }

    while (!q.empty()) {
        auto [aa, b] = q.front(); q.pop();
        auto [a, k] = aa;

        for (auto &[p, o] : axes) {
            int pb = b.first + p, ob = b.second + o;
            if (pb >= 0 && pb < r && ob >= 0 && ob < c) {

                if ((l1[pb][ob] != a) && (l2[pb][ob] == -1 || (dist2[pb][ob] == k + 1 && a < l2[pb][ob]))) {
                    dist2[pb][ob] = k + 1;
                    l2[pb][ob] = a;
                    q.push({{a, dist2[pb][ob]}, {pb, ob}});
                } else if (dist2[pb][ob] >= 1e9) {
                    dist2[pb][ob] = 1e9 - 1;
                    q.push({{a, k+1}, {pb, ob}});
                }
            }
        }
    }
}

void bfs(vector<pair<int, int>> &points) {
    l1.assign(r, vector<int>(c, -1));
    l2.assign(r, vector<int>(c, -1));
    dist1.assign(r, vector<int>(c, 1e9));
    dist2.assign(r, vector<int>(c, 1e9));

    queue<pair<pair<int, int>, pair<int, int>>> q;

    for (int i = 0; i < n; i++) {
        l1[points[i].first][points[i].second] = i+1;
        dist1[points[i].first][points[i].second] = 0;
        q.push({{i+1, 0}, {points[i].first, points[i].second}});
    }

    while (!q.empty()) {
        auto [aa, b] = q.front(); q.pop();
        auto [a, k] = aa;

        for (auto &[p, o] : axes) {
            int pb = b.first + p, ob = b.second + o;
            if (pb >= 0 && pb < r && ob >= 0 && ob < c) {
                if (l1[pb][ob] == -1 || (dist1[pb][ob] == dist1[b.first][b.second] + 1 && a < l1[pb][ob])) {
                    dist1[pb][ob] = dist1[b.first][b.second] + 1;
                    l1[pb][ob] = a;
                    q.push({{a, dist1[pb][ob]}, {pb, ob}});
                }
            }
        }
    }

    bfs2(points);
}


int main() {
    scanf("%d %d %d", &r, &c, &n);

    vector<pair<int, int>> points;

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        points.push_back({a-1, b-1});
    }


    bfs(points);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", l1[i][j]);
        }
        printf("\n");
    }
    

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", l2[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}