#include <bits/stdc++.h>
using namespace std;

int n, m, t, s, g, h;
vector<vector<int>> dist;
vector<vector<pair<int, int>>> AL;
vector<int> ts;

vector<int> djikstra() {
    dist.assign(n+1, vector<int>(2, 1e9));
    dist[s][0] = 0;
    set<tuple<long long, int, int>> pm;
    for (int i = 1; i <= n; i++) {
        pm.emplace(dist[i][0], i, 0);
        pm.emplace(dist[i][1], i, 1);
    }

    while (!pm.empty()) {
        auto [a, u, c] = *pm.begin();
        pm.erase(pm.begin());

        for (auto [v, w] : AL[u]) {
            int k = c;
            if ((u == g && v == h) || (u == h && v == g)) k = 1;
            if (dist[u][c] + w >= dist[v][k]) continue;
            pm.erase(pm.find({dist[v][k], v, k}));
            dist[v][k] = dist[u][c]+w;
            pm.emplace(dist[v][k], v, k);
        }
    }

    vector<int> ans {};
    for (int i = 0; i < t; i++) if (dist[ts[i]][1] <= dist[ts[i]][0] && dist[ts[i]][1] != 1e9) {
        ans.push_back(ts[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d %d %d %d %d", &n, &m, &t, &s, &g, &h);
        AL.assign(n+1, {});
        ts.assign(t, 0);

        for (int i = 0; i < m; i++) {
            int a, b, d;
            scanf("%d %d %d", &a, &b, &d);
            AL[a].push_back({b, d});
            AL[b].push_back({a, d});
        }

        for (int &i : ts) {
            scanf("%d", &i);
        }
        
        vector<int> res = djikstra();
        for (int i : res) {
            printf("%d ", i);
        }
        printf("\n");

    }

    return 0;
}