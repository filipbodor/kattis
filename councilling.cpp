#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
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
                if ((cap-flow > 0) && (d[v] == -1)) {
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
            while(ll f = DFS(s, t)) {
                mf += f;
            }
        }
        return mf;
    }

    vector<pair<int, int>> find_ans(int offset1, int size1) {
        vector<pair<int, int>> ans {};
        for (int i = offset1; i < offset1 + size1; i++) {
            for (int j = 0; j < (int)AL[i].size(); j++) {
                auto &[v, cap, flow] = EL[AL[i][j]];
                if (flow > 0) ans.push_back({i, v});
            }
        }
        return ans;
    }

    void prints() {
        for (int i = 0; i < (int)AL.size(); i++) {
            printf("%d: ", i);
            for (int j = 0; j < AL[i].size(); j++) {
                auto &[v, cap, flow] = EL[AL[i][j]];
                printf("%d [%d] ", v, cap);
            }
            printf("\n");
        }
    }

};

int main() {

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<string> names(n);
        vector<int> par(n);
        vector<vector<int>> clubs(n, vector<int>());
        vector<string> parties {};
        unordered_map<string, int> parties_idx;
        vector<string> clu {};
        unordered_map<string, int> clu_idx;

        for (int i = 0; i < n; i++) {
            cin >> names[i];
            string a;
            cin >> a;
            if (parties_idx.find(a) == parties_idx.end()) {
                parties.push_back(a);
                parties_idx[a] = parties.size() - 1;
            }
            par[i] = parties_idx[a];

            int m;
            cin >> m;
            for (int j = 0; j < m; j++) {
                string b;
                cin >> b;
                if (clu_idx.find(b) == clu_idx.end()) {
                    clu.push_back(b);
                    clu_idx[b] = clu.size() - 1; 
                }
                clubs[i].push_back(clu_idx[b]);
            }
        }

        int offset1 = 1 + (int)parties.size();
        int offset2 = 1 + (int)parties.size() + n;
        int sink = 1 + (int)parties.size() + n + (int)clu.size();

        max_flow maf(sink+1);
        for (int i = 0; i < (int)parties.size(); i++) {
            maf.add_edge(0, 1 + i, ((int)clu.size() + 1) / 2 - 1);
        }
        for (int i = 0; i < n; i++) {
            maf.add_edge(1 + par[i], offset1 + i, 1);
        }
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < (int)clubs[i].size(); j++) {
                maf.add_edge(offset1 + i, offset2 + clubs[i][j], 1);
            }
        }
        for (int j = 0; j < (int)clu.size(); j++) {
            maf.add_edge(offset2 + j, sink, 1);
        }



        ll mf = maf.dinic(0, sink);
        if (mf == clu.size()) {
            vector<ii> ans = maf.find_ans(offset1, n);

            for (int i = 0; i < (int)ans.size(); i++) {
                cout << names[ans[i].first - offset1] << ' ' << clu[ans[i].second - offset2] << endl;
            }
        } else {
            cout << "Impossible." << endl;
        }

        if (T > 0) cout << endl;
    }

    return 0;
}