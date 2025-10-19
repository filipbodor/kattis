#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef tuple<int, ll, ll> edge;
typedef pair<int, int> ii;

const ll INF = 1e18;

vector<ii> axes {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class max_flow {
private:
    int V;
    vector<edge> EL;
    vector<vi> AL;
    vi last, d;
    vector<ii> p;

    bool BFS(int s, int t) {
        d.assign(V, -1); d[s] = 0;
        queue<int> q({s});
        p.assign(V, {-1, -1});
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t) break;
            for (int &idx : AL[u]) {
                auto &[v, cap, flow] = EL[idx];
                if ((cap - flow) > 0 && d[v] == -1) {
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

    int n, m;
    scanf("%d %d", &n, &m);

    vector<vi> mat(n, vi(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int x, y;
    scanf("%d %d", &x, &y);

    int sink = n * m * 2 + 1;

    max_flow maf(sink+1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (mat[i][j] != 0) {
            maf.add_edge(i*m+j+1, i*m+j+1 + (m*n), mat[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (mat[i][j] != 0) {
            for (auto &[p, q] : axes) {
                int ip = i+p, jq = j+q;
                if (ip >= 0 && ip < n && jq >= 0 && jq < m && mat[ip][jq] != 0) {
                    maf.add_edge(i*m+j+1 + (m*n), ip*m+jq+1, 1e9);
                }
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        if (mat[0][i-1] != 0) maf.add_edge(0, i, 1e9);
    }

    for (int i = 2; i < n; i++) {
        if (mat[i-1][0] != 0) maf.add_edge(0, (i-1)*m+1, 1e9);
    }
    for (int i = 1; i <= m; i++) {
        if (mat[n-1][i-1] != 0) maf.add_edge(0, (n-1)*m+i, 1e9);
    }
    for (int i = 2; i < n; i++) {
        if (mat[i-1][m-1] != 0) maf.add_edge(0, i*m, 1e9);
    }

    maf.add_edge(x*m+y+1 + (m*n), sink, 1e9);

    //maf.prints();

    ll ans = maf.dinic(0, sink);
    printf("%lld\n", ans);




    return 0;
}