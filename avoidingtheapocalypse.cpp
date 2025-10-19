#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef pair<int, int> ii;

const ll INF = 1e18;

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
};

int main() {

    int T;
    scanf("%d", &T);

    while (T--) {
        int n, i, g, s, m;
        scanf("%d %d %d %d %d", &n, &i, &g, &s, &m);

        vector<int> meds(m);

        for (int j = 0; j < m; j++) {
            scanf("%d", &meds[j]);
        }

        int r;
        scanf("%d", &r);
        vector<vi> edg(r, vi(4));
        for (int j = 0; j < r; j++) {
            int a, b, p, t;
            scanf("%d %d %d %d", &edg[j][0], &edg[j][1], &edg[j][2], &edg[j][3]);
        }


        int sink = n * s + 1 + n;
        max_flow maf(sink + 1);


        maf.add_edge(0, i, g);
        for (int j = 0; j < s; j++) {
            for (int k = 0; k < r; k++) {
                if (j + edg[k][3] <= s) maf.add_edge(edg[k][0] + j*n, edg[k][1] + (j+edg[k][3])*n, edg[k][2]);
            }
        }

        for (int j = 0; j < s - 1; j++) {
            maf.add_edge(i + j*n, i + (j+1)*n, g);
        }

        for (int j = 0; j <= s; j++) {
            for (int k = 0; k < m; k++) {
                maf.add_edge(meds[k] + j*n, sink, 1e9);
            }
        }   

        //maf.prints();

        ll mf = maf.dinic(0, sink);
        printf("%lld\n", mf);

    }

    return 0;
}