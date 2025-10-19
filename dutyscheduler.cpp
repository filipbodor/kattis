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
                if (((cap-flow) > 0) && (d[v] == -1)) {
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
        AL[u].push_back(EL.size() - 1);
        EL.emplace_back(u, directed ? 0 : w, 0);
        AL[v].push_back(EL.size() - 1);
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

    vector<vi> ans(int i, int j) {
        vector<vi> a(j - i + 1, vi());
        for (int k = 1; k < i; k++) {
            for (int l : AL[k]) {
                auto &[v, cap, flow] = EL[l];
                if (flow > 0) {
                    a[v - i].push_back(k - 1);
                }
            }
        }
        return a;
    }

};

int main() {
    int n, m;
    scanf("%d %d", &m, &n);

    vector<string> names(m);
    vector<vector<int>> avai(m, vector<int>(n + 1, 0));


    for (int i = 0; i < m; i++) {
        char name[35];
        int nn;
        scanf("%s %d", &name, &nn);
        names[i] = name;
        for (int j = 0; j < nn; j++) {
            int a;
            scanf("%d", &a);
            avai[i][a] = 1;
        }
    }


    for (int i = 1; i <= n; i++) {
        max_flow maf(2 + m + n);
        for (int j = 1; j <= m; j++) {
            maf.add_edge(0, j, i);
        }
        for (int j = 1; j <= m; j++) {
            for (int k = m + 1; k < m + n + 1; k++) {
                if (avai[j-1][k - m]) maf.add_edge(j, k, 1);
            }
        }
        for (int k = m + 1; k < m + n + 1; k++) {
            maf.add_edge(k, 1 + m + n, 2);
        }


        if (maf.dinic(0, 1 + m + n) == 2 * n) {
            printf("%d\n", i);
            vector<vi> an = maf.ans(m + 1, m + n);
            for (int j = 0; j < n; j++) {
                printf("Day %d:", j+1);
                for (int k = 0; k < an[j].size(); k++) {
                    printf(" %s", names[an[j][k]].c_str());
                }
                printf("\n");
            } 
            break;
        }
    }



    return 0;
}