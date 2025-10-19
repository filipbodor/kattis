#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> AL;
vector<vector<int>> AL_T;
vector<int> visited;
vector<int> visited_t;

void dfs(int u) {
    visited[u] = 1;

    for (int v : AL[u]) if (visited[v] == -1) {
        dfs(v);
    }
}

void dfsT(int u, vector<int> &c) {
    visited_t[u] = 1;

    c.push_back(u);

    for (int v : AL_T[u]) if (visited_t[v] == -1 && visited[v] == -1) {
        dfsT(v, c);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);

        vector<int> no(n+1, 0);
        visited.assign(n+1, -1);
        AL.assign(n+1, {});
        AL_T.assign(n+1, {});

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            no[b]++;
            AL[a].push_back(b);
            AL_T[b].push_back(a);
        }

        vector<int> start {};
        for (int i = 1; i <= n; i++) {
            if (no[i] == 0) start.push_back(i);
        }

        int cou = start.size();
        for (int i : start) if (visited[i] == -1) {
            dfs(i);
        }

        for (int i = 1; i <= n; i++) if (visited[i] == -1) {
            visited_t = visited;
            vector<int> c {};
            dfsT(i, c);
            dfs(c[(int)c.size() - 1]);
            cou++;
        }

        printf("%d\n", cou);
    }

    return 0;
}