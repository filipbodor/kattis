#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
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
                if ((cap-flow > 0) && (d[v] == -1)) {
                    d[v] = d[u] + 1, q.push(v), p[v] = {u, idx};
                }
            }
        }

        return d[t] != -1;
    }

    ll DFS(int u, int t, ll f = INF) {
        if ((u == t) || (f == 0)) return f;
        for (int &i = last[u]; i < (int)AL[u].size(); i++) {
            auto &[v, cap, flow] = EL[AL[u][i]];
            if (d[v] != d[u] + 1) continue;
            if (ll pushed = DFS(v, t, min(f, cap-flow))) {
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

};

int main() {
    int n, q, s;
    scanf("%d %d %d", &n, &q, &s);

    vector<int> qs(s);
    for (int &e : qs) scanf("%d", &e), --e;
    vector<int> ca(q);
    for (int &e : ca) scanf("%d", &e);

    int offset1 = s*n + 1;
    int offset2 = s*n + q*n + 1;
    int offset3 = s*n + 2*q*n + 1;
    int offset4 = s*n + 2*q*n + n + 1;

    ll al = 0;


    max_flow mf(s*n + 2*q*n + n + 2);

    for (int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);

        for (int j = 0; j < s; j++) {
            int a;
            scanf("%d", &a);
            al += (ll)a;

            mf.add_edge(0, 1 + i*s + j, a);
            mf.add_edge(1 + i*s + j, offset1 + i*q + qs[j], ca[qs[j]]);
        }

        for (int j = 0; j < q; j++) {
            mf.add_edge(offset1 + i*q + j, offset2 + i*q + j, ca[j]);
            mf.add_edge(offset2 + i*q + j, offset3 + i, ca[j]);
            if (i < n-1) {
                mf.add_edge(offset2 + i*q + j, offset1 + q*i + q + j, ca[j]);
            }
        }

        mf.add_edge(offset3 + i, offset4, d);
    }
    ll ma = mf.dinic(0, offset4);
    if (ma == al) {
        printf("possible\n");
    } else {
        printf("impossible\n");
    }




    return 0;
}