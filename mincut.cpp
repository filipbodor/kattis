#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef pair<int, int> ii;

const ll INF = 1e18;

vi visited;

class max_flow {
private:
    int V;
    vector<edge> EL;
    vector<vi> AL;
    vi d, last;
    vector<ii> p;

    bool BFS(int s, int t) {
        d.assign(V, -1); d[s] = 0;
        queue<int> q({s});
        p.assign(V, {-1, -1});
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t) break;
            for (auto &idx : AL[u]) {
                auto &[v, cap, flow] = EL[idx];
                if ((cap - flow > 0) && (d[v] == -1)) {
                    d[v] = d[u] + 1, q.push(v), p[v] = {u, idx};
                }
            }
        }

        return d[t] != -1;
    }

    ll DFS(int u, int t, ll f = INF) {
        if ((u == t) || f == 0) return f;
        for (int &i = last[u]; i < (int)AL[u].size(); i++) {
            auto &[v, cap, flow] = EL[AL[u][i]];
            if (d[v] != d[u] + 1) continue;
            if (ll pushed = DFS(v, t, min(cap-flow, f))) {
                flow += pushed;
                auto &rflow = get<2>(EL[AL[u][i]^1]);
                rflow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

public:
    max_flow(int initialV) : V(initialV) {
        EL.clear();
        AL.assign(V, vi());
    }

    void add_edge(int u, int v, ll w, bool directed = true) {
        if (u == v) return;
        EL.emplace_back(v, w, 0);
        AL[u].push_back(EL.size()-1);
        EL.emplace_back(u, directed ? 0 : w, 0);
        AL[v].push_back(EL.size()-1);
    }

    ll dinic(int s, int t) {
        ll mf = 0;
        while (BFS(s, t)) {
            last.assign(V, 0);
            while (ll f = DFS(s, t)) {
                mf += f;
            }
        }

        return mf;
    }

    void prints() {
        for (int i = 0; i < AL.size(); i++) {
            printf("%d: ", i);
            for (int j = 0; j < AL[i].size(); j++) {
                auto &[v, cap, flow] = EL[AL[i][j]];
                printf("%d [%d], ", v, cap);
            }
            printf("\n");
        }
    }

    int ansDFS(int u, bool pri) {
        if (pri) printf("%d\n", u);
        int cnt = 1;
        visited[u] = 1;
        for (int &idx : AL[u]) {
            auto &[v, cap, flow] = EL[idx];
            if (visited[v] != -1) continue;
            if ((cap - flow) > 0) cnt += ansDFS(v, pri);
        }
        return cnt;
    }
};

int main() {
    int n, m, s, t;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    
    max_flow maf(n);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        maf.add_edge(a, b, w);
    }

    ll mf = maf.dinic(s, t);

    visited.assign(n, -1);
    printf("%d\n", maf.ansDFS(s, false));

    visited.assign(n, -1);
    maf.ansDFS(s, true);





    return 0;
}