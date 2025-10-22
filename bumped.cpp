#include <bits/stdc++.h>
using namespace std;

int n, m, f, s, t;
vector<vector<long long>> dist;
vector<vector<pair<int, int>>> AL;
vector<vector<int>> ALf;

long long djikstra() {
    dist.assign(n, vector<long long>(2, 1e18));
    dist[s][0] = 0;
    set<tuple<long long, int, int>> pm;
    for (int i = 0; i < n; i++) {
        pm.emplace(dist[i][0], i, 0);
        pm.emplace(dist[i][1], i, 1);
    }


    while (!pm.empty()) {
        auto [a, u, c] = *pm.begin();
        pm.erase(pm.begin());

        for (auto [v, w] : AL[u]) {
            if (dist[u][c] + w >= dist[v][c]) continue;
            pm.erase(pm.find({dist[v][c], v, c}));
            dist[v][c] = dist[u][c]+w;
            pm.emplace(dist[v][c], v, c);
        }

        if (c == 1) continue;
        for (int v : ALf[u]) {
            if (dist[u][0] >= dist[v][1]) continue;
            pm.erase(pm.find({dist[v][1], v, 1}));
            dist[v][1] = dist[u][0];
            pm.emplace(dist[v][1], v, 1);
        }
    }


    return min(dist[t][1], dist[t][0]);

}

int main() {
    scanf("%d %d %d %d %d", &n, &m, &f, &s, &t);
    AL.assign(n, {});
    ALf.assign(n, {});

    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        AL[a].push_back({b, c});
        AL[b].push_back({a, c});
    }

    for (int i = 0; i < f; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        ALf[a].push_back(b);
    }


    long long res = djikstra();

    printf("%ld\n", res);




    return 0;
}