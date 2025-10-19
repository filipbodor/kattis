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

    int n;
    scanf("%d", &n);

    vi nums(n);
    for (int &i : nums) scanf("%d", &i);

    max_flow maf(n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int l = gcd(nums[i], nums[j]);

            if (l != 1) {
                maf.add_edge(i, j, l, false);
            }
        }
    }

    int mi = 0;
    int ma = 0;

    for (int i = 1; i < n; i++) {
        if (nums[mi] > nums[i]) mi = i;
        if (nums[ma] < nums[i]) ma = i;
    }

    ll mf = maf.dinic(mi, ma);

    printf("%lld\n", mf);

    return 0;
}