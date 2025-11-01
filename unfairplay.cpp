#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef pair<int, int> ii;

const ll INF = 1e18;


int n, m;

vector<pair<int, int>> mas;

class MaxFlow {
private:
    int V;
    vector<edge> EL;
    vector<vi> AL;
    vi d, last;
    vector<ii> p;

    bool bfs(int s, int t) {
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

    ll dfs(int u, int t, ll f = INF) {
        if ((u == t) || (f == 0)) return f;
        for (int &i = last[u]; i < (int)AL[u].size(); i++) {
            auto &[v, cap, flow] = EL[AL[u][i]];
            if (d[v] != d[u] + 1) continue;
            if (ll pushed = dfs(v, t, min(f, cap-flow))) {
                flow += pushed;
                auto &rflow = get<2>(EL[AL[u][i]^1]);
                rflow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

public:
    MaxFlow(int iV) : V(iV) {
        EL.clear();
        AL.assign(V, vi());
    }

    void add_edge(int u, int v, ll w) {
        if (u == v) return;
        EL.emplace_back(v, w, 0);
        AL[u].push_back(EL.size() - 1);
        EL.emplace_back(u, 0, 0);
        AL[v].push_back(EL.size() - 1);
    }

    ll dinic(int s, int t) {
        ll mf = 0;
        while (bfs(s, t)) {
            last.assign(V, 0);
            while (ll f = dfs(s, t)) {
                mf += f;
            }
        }
        return mf;
    }

    void prin(vector<int> &res, int offset1) {
        for (int i = 1; i <= res.size(); i++) {
            for (int u : AL[i]) {
                auto &[v, cap, flow] = EL[u];
                if (v == 0) continue;
                if (flow == 1) {
                    res[i-1] = 1;
                } else if (mas[i-1].first == v - offset1 + 1) {
                    res[i-1] = 2 - flow;
                }
            }
        }
    }
};



int main() {

    while (scanf("%d %d", &n, &m) == 2) {
        vector<int> scs(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &scs[i]);
        }
        vector<int> res(m, -1);
        mas.assign(m, {});

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            mas[i] = {a, b};

            if (a == n) {
                res[i] = 0;
                scs[n] += 2;
            } else if (b == n) {
                res[i] = 2;
                scs[n] += 2;
            }
        }
        bool flag = true;
        for (int i = 1; i < n && flag; i++) {
            if (scs[i] >= scs[n]) {
                flag = false;
            }
        }
        if (!flag) {
            printf("NO\n");
            continue;
        }


        int offset1 = m + 1;
        int sink = offset1 + n;

        MaxFlow maf(sink + 1);

        for (int i = 1; i <= m; i++) {
            maf.add_edge(0, i, 2);
        }

        ll tot = 0;

        for (int i = 0; i < m; i++) {
            if (res[i] == -1) {
                tot += 2;
                maf.add_edge(1 + i, offset1 + mas[i].first - 1, 2);
                maf.add_edge(1 + i, offset1 + mas[i].second - 1, 2);
            }
        }

        for (int i = 1; i < n; i++) {
            maf.add_edge(offset1 + i - 1, sink, scs[n] - scs[i] - 1);
        }

        ll mf = maf.dinic(0, sink);

        if (mf == tot) {
            maf.prin(res, offset1);

            // for (int i = 0; i < m; i++) {
            //     if (res[i] == 1) {
            //         scs[mas[i].first]++;
            //         scs[mas[i].second]++;
            //     } else {
            //         if (res[i] == 2 && mas[i].first != n) {
            //             scs[mas[i].first] += 2;
            //         }
            //         if (res[i] == 0 && mas[i].second != n) {
            //             scs[mas[i].second] += 2;
            //         }
            //     }
            // }

            // for (int i = 0; i < n; i++) {
            //     printf("%d ", scs[i+1]);
            // }
            // printf("\n");

            for (int i = 0; i < m; i++) {
                printf("%d ", res[i]);
            }
            printf("\n");
        } else {
            printf("NO\n");
        }


    }

    return 0;
}